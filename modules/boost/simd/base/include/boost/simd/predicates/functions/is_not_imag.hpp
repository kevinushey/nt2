//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_IMAG_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_IMAG_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief is_not_imag generic tag

     Represents the is_not_imag function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct is_not_imag_ : ext::elementwise_<is_not_imag_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<is_not_imag_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_is_not_imag_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };}
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::is_not_imag_, Site> dispatching_is_not_imag_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::is_not_imag_, Site>();
   }
   template<class... Args>
   struct impl_is_not_imag_;
  }
  /*!
    Returns True or False according a0 is real or not.
    For non complex numbers it is true except if a0 is zero

    @par Semantic:

    @code
    logical<T> r = is_not_imag(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0 != 0;
    @endcode

    @param a0

    @return a logical value
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_imag_, is_not_imag,   1)
} }

#endif

