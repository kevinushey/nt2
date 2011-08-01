/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::meta::as_real SIMD"

#include <boost/simd/sdk/simd/native.hpp>
#include <boost/dispatch/meta/as_real.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/simd/sdk/unit/tests/basic.hpp>
#include <boost/simd/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test that as_real on SIMD
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE_TPL(as_real_simd, BOOST_SIMD_REAL_TYPES)
{
  using boost::simd::native;
  using boost::dispatch::meta::as_real;
  using boost::is_same;
  using boost::mpl::_;

  typedef BOOST_SIMD_DEFAULT_EXTENSION                ext_t;
  typedef native<typename as_real<T>::type,ext_t> dst_t;

  BOOST_SIMD_TEST( (is_same< typename as_real< native<T,ext_t> >::type
                    , dst_t
                    >::value
            )
          );
}
