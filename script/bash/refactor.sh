#!/bin/bash

function perl-sed() {
  perl -p -0777 -i -e "$@"
}

# files that define functions
functions=$(find . -regextype posix-egrep -regex '.*/(functions|constants)/[^/]+\.hpp' | grep -Ev 'include/(functions|constants|nt2/cuda)')

# files that can add specializations to functions
specializations=$(find . -not -regex '.*/preprocessor/.*' -name '*.hpp' -o -name '*.cpp')

echo "function definitions"
echo "$functions" | while read i
do
  echo "$i"

  #tag = \7
  #parent = $10
  #contenu = $14
  perl-sed 's/namespace tag(\s*){(\s*)(.*?)?(\s*)(template\s*<[^>]+>\s*)struct(\s*)([a-zA-Z0-9_]+)(\s*):(\s*)([^\n\}]+)(\s*)({(\s*)([^{}]+?|(?12))(\s*)});(\s*)}(\s*)/namespace tag\1\{\2\3\4\5struct\6\7\8:\9$10$11\{$13$14$15  template<class... Args>$15  static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatching(Args&&... args)$15  BOOST_AUTO_DECLTYPE_BODY( dispatching( ext::adl_helper(), \7(), static_cast<Args&&>(args)... ) )$15\};$16\}$17/gs' "$i"

  #tag = \6
  #parent = \9
  #contenu = $12
  perl-sed 's/namespace tag(\s*){(\s*)(.*?)?(\s*)struct(\s*)([a-zA-Z0-9_]+)(\s*):(\s*)([^\n\}]+)(\s*)({(\s*)([^{}]+?|(?11))(\s*)});(\s*)}(\s*)/namespace tag\1\{\2struct \6;\1\}\1namespace ext\1\{\2template<class... H>\2BOOST_FORCEINLINE generic_dispatcher<tag::\6, sizeof...(H)> dispatching_\6(adl_helper, boost::dispatch::meta::unspecified_<H>...)\2\{\2  return generic_dispatcher<tag::\6, sizeof...(H)>();\2\}\2template<class... Args>\2struct impl_\6;\1\}\1namespace tag\1\{\2\3\4struct\5\6\7:\8\9$10\{$12$13$14  template<class... Args>$14  static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatching(Args&&... args)$14  BOOST_AUTO_DECLTYPE_BODY( dispatching_\6( ext::adl_helper(), static_cast<Args&&>(args)... ) )$14\};$15\}$16/gs' "$i"

  #tag = \6
  perl-sed 's/namespace tag(\s*){(\s*)(.*?)?(\s*)BOOST_SIMD_CONSTANT_REGISTER\((\s*)([a-zA-Z0-9_]+)(\s*),([^)]+)\)(\s*)}(\s*)/namespace tag\1\{\2struct \6;\1\}\1namespace ext\1\{\2template<class... H>\2BOOST_FORCEINLINE generic_dispatcher<tag::\6, sizeof...(H)> dispatching_\6(adl_helper, boost::dispatch::meta::unspecified_<H>...)\2\{\2  return generic_dispatcher<tag::\6, sizeof...(H)>();\2\}\2template<class... Args>\2struct impl_\6;\1\}\1namespace tag\1\{\2\3\4BOOST_SIMD_CONSTANT_REGISTER(\5\6\7,\8)\9\}$10/gs' "$i"

done

echo "function specializations"
echo "$specializations" | while read i
do
  echo "$i"

  # remove nt2::tag:: / boost::simd::tag::
  perl-sed 's/(NT2|BOOST_SIMD)_(FUNCTOR_IMPLEMENTATION|REGISTER_DISPATCH)(_TO)?(_TPL)?(_IF)?(\s*)\((\s*)([:a-zA-Z0-9_]+?)::tag::([a-zA-Z0-9#_]+)(\s*)(,|\n|\\)/BOOST_DISPATCH_@{[ $2 eq "FUNCTOR_IMPLEMENTATION" ? "IMPLEMENT" : "REGISTER" ]}\3\4\5@{[ " " x (length($1) - ($2 eq "FUNCTOR_IMPLEMENTATION" ? 1 : 5)) ]}\6(\7\9$10$11/g' "$i"

  # for cases that include template arguments, use the _G variant
  perl-sed 's/(NT2|BOOST_SIMD)_(FUNCTOR_IMPLEMENTATION|REGISTER_DISPATCH)(_TO)?(_TPL)?(_IF)?(\s*)\((\s*)([:a-zA-Z0-9#_<>\s]+)(\s*)(,|\n|\\)/BOOST_DISPATCH_@{[ $2 eq "FUNCTOR_IMPLEMENTATION" ? "IMPLEMENT" : "REGISTER" ]}_G\3\4\5@{[ " " x (length($1) - ($2 eq "FUNCTOR_IMPLEMENTATION" ? 3 : 7)) ]}\6(\7\8\9$10/g' "$i"
done