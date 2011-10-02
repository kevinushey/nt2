//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SIGNMASK_HPP_INCLUDED

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/meta/float.hpp>
#include <boost/simd/sdk/meta/int_c.hpp>
#include <boost/simd/sdk/meta/double.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup signmask Signmask function
 *
 * \par Description
 * Constant Signmask
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/signmask.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::signmask_(A0)>::type
 *     Signmask();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Signmask
 * 
 * \return type T value
 *  
 *  
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag Signmask of functor Signmask 
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    struct Signmask 
    { 
      template<class Target, class Dummy=void> 
      struct apply : meta::int_c<Target,0> {};  
    };

    template<class Dummy>
    struct  Signmask::apply<float,Dummy> 
          : meta::single_<0x80000000UL> {};

    template<class Dummy>
    struct  Signmask::apply<double,Dummy> 
          : meta::double_<0x8000000000000000ULL> {};

    template<class Dummy>
    struct  Signmask::apply<boost::simd::int8_t,Dummy> 
          : meta::int_c<boost::simd::int8_t,boost::simd::uint8_t(0x80)> {};

    template<class Dummy>
    struct  Signmask::apply<boost::simd::int16_t,Dummy> 
          : meta::int_c<boost::simd::int16_t,boost::simd::uint16_t(0x8000U)> {};

    template<class Dummy>
    struct  Signmask::apply<boost::simd::int32_t,Dummy> 
          : meta::int_c<boost::simd::int32_t,boost::simd::uint32_t(0x80000000UL)> {};

    template<class Dummy>
    struct  Signmask::apply<boost::simd::int64_t,Dummy> 
          : meta::int_c<boost::simd::int64_t,boost::simd::uint64_t(0x8000000000000000ULL)> {};
  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Signmask, Signmask)
} }

#endif
