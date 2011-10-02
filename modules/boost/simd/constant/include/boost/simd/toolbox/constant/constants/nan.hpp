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
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_NAN_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_NAN_HPP_INCLUDED

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/register.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup nan Nan function
 *
 * \par Description
 * Constant Nan
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/nan.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::nan_(A0)>::type
 *     Nan();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Nan
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
     * \brief Define the tag Nan of functor Nan 
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    BOOST_SIMD_CONSTANT_REGISTER( Nan, double, 0
                                , 0xFFFFFFFF, 0xFFFFFFFFFFFFFFFFULL
                                );
  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Nan, Nan)
} }

#endif
