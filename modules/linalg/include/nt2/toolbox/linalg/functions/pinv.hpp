/*******************************************************************************
 *         Copyright 2003-2012 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_PINV_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_PINV_HPP_INCLUDED
#include <nt2/include/functor.hpp>
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <nt2/sdk/memory/container.hpp>

/*!
 * \ingroup algebra
 * \defgroup algebra_pinv pinv
 *
 * \par Description
 * Elementary Least square
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/pinv.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \param a the matrix or vector expression a 
 *
 * \par Notes
 *   use lapack svd.
 * \par
 *  
**/

namespace nt2 { namespace tag
  {         
    /*!
     * \brief Define the tag pinv_ of functor pinv
     *        in namespace nt2::tag for toolbox algebra
    **/
    struct pinv_ :  tag::formal_ { typedef tag::formal_ parent; };
  }
  
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::pinv_, pinv, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::pinv_, pinv, 2)

}

#endif

