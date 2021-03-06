//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief is_not_less_equal generic tag

     Represents the is_not_less_equal function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct is_not_less_equal_ : ext::elementwise_<is_not_less_equal_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<is_not_less_equal_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_is_not_less_equal_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };}
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::is_not_less_equal_, Site> dispatching_is_not_less_equal_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::is_not_less_equal_, Site>();
   }
   template<class... Args>
   struct impl_is_not_less_equal_;
  }
   /*!
    @par Semantic:

    @code
    logical<T> r = is_not_less_equal(a0,a1);
    @endcode

    is similar to:

    @code
    logical<T> r = !(a0 <= a1);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_greater(a0, a1)
    for floating types

    @par Alias:

    @c is_nle

    @param a0

    @param a1

    @return a logical value
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_less_equal_, is_not_less_equal, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_less_equal_, is_nle, 2)
} }

#endif
