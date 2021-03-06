//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_REAL_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_REAL_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief is_not_real generic tag

     Represents the is_not_real function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct is_not_real_ : ext::elementwise_<is_not_real_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<is_not_real_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_is_not_real_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };}
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::is_not_real_, Site> dispatching_is_not_real_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::is_not_real_, Site>();
   }
   template<class... Args>
   struct impl_is_not_real_;
  }
  /*!
    Returns True or False according a0 is real or not.
    For non complex numbers it is always false

    @par Semantic:

    @code
    logical<T> r = is_not_real(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = False;
    @endcode

    @param a0

    @return a logical value
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_real_, is_not_real,   1)
} }

#endif

