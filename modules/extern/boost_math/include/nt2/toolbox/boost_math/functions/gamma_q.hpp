//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_GAMMA_Q_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_GAMMA_Q_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <boost/math/special_functions/gamma.hpp>

/*!
 * \ingroup boost_math
 * \defgroup boost_math_gamma_q gamma_q
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library boost_math.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/boost_math/include/functions/gamma_q.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace boost_math
 *   {
 *     template <class A0>
 *       meta::call<tag::gamma_q_(A0,A0)>::type
 *       gamma_q(const A0 & a0,const A0 & a1);
 *   }
 * }
 * \endcode
 *
 * \param a0 the first parameter of gamma_q
 * \param a1 the second parameter of gamma_q
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * When calling external library, nt2 simply encapsulates the
 * original proper call to provide easy use.
 * \par
 * Remenber that SIMD implementation is therefore merely
 * mapping the scalar function to each SIMD vectors elements
 * and will not provide acceleration, but ease.
 *
**/

namespace nt2 { namespace boost_math { namespace tag
  {
    /*!
     * \brief Define the tag gamma_q_ of functor gamma_q
     *        in namespace nt2::boost_math::tag for toolbox boost_math
    **/
    struct gamma_q_ : ext::elementwise_<gamma_q_> { typedef ext::elementwise_<gamma_q_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(boost_math::tag::gamma_q_, gamma_q, 2)
  } }

#include <nt2/toolbox/boost_math/functions/scalar/gamma_q.hpp>
// #include <nt2/toolbox/boost_math/functions/simd/all/gamma_q.hpp>

#endif

// modified by jt the 29/12/2010
