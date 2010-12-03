//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - idivceil/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in scalar 
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/toolbox/arithmetic/include/idivceil.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include<nt2/include/functions/ceil.hpp>

NT2_TEST_CASE_TPL ( idivceil_real_,  NT2_REAL_TYPES)
{
  using nt2::idivceil;
  using nt2::functors::idivceil_;
  typedef typename nt2::meta::call<idivceil_(T, T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // specific values tests
  NT2_TEST_ULP_EQUAL(  idivceil(4,3), 2, 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Inf<T>(), nt2::Inf<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Minf<T>(), nt2::Minf<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Mone<T>(), nt2::Mone<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Nan<T>(), nt2::Nan<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Nan<T>(), 0);

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random comparison with other impl or formula 
  static const uint32_t N = 100;
  NT2_CREATE_BUFFER(a0, T, 100, T(-10), T(10));
  NT2_CREATE_BUFFER(a1, T, 100, T(-10), T(10));
  for (int j =0; j < N; ++j )
    {
      std::cout << "for params "
                << "  a0 = "<< u_t(a0 = tab_a0[j])
                << ", a1 = "<< u_t(a1 = tab_a1[j])
                << std::endl;
      NT2_TEST_ULP_EQUAL( nt2::idivceil(a0,a1), r_t(nt2::ceil((1.0*a0)/a1)),0);
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( idivceil_unsigned_int_,  NT2_UNSIGNED_TYPES)
{
  using nt2::idivceil;
  using nt2::functors::idivceil_;
  typedef typename nt2::meta::call<idivceil_(T, T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // specific values tests
  NT2_TEST_ULP_EQUAL(  idivceil(4,3), 2, 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random comparison with other impl or formula 
  static const uint32_t N = 100;
  NT2_CREATE_BUFFER(a0, T, 100, 0, 100);
  NT2_CREATE_BUFFER(a1, T, 100, 0, 100);
  for (int j =0; j < N; ++j )
    {
      std::cout << "for params "
                << "  a0 = "<< u_t(a0 = tab_a0[j])
                << ", a1 = "<< u_t(a1 = tab_a1[j])
                << std::endl;
      NT2_TEST_ULP_EQUAL( nt2::idivceil(a0,a1), r_t(nt2::ceil((1.0*a0)/a1)),0);
   }
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( idivceil_signed_int_,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::idivceil;
  using nt2::functors::idivceil_;
  typedef typename nt2::meta::call<idivceil_(T, T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // specific values tests
  NT2_TEST_ULP_EQUAL(  idivceil(4,3), 2, 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Mone<T>(), nt2::Mone<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  idivceil(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random comparison with other impl or formula 
  static const uint32_t N = 100;
  NT2_CREATE_BUFFER(a0, T, 100, -100, 100);
  NT2_CREATE_BUFFER(a1, T, 100, -100, 100);
  for (int j =0; j < N; ++j )
    {
      std::cout << "for params "
                << "  a0 = "<< u_t(a0 = tab_a0[j])
                << ", a1 = "<< u_t(a1 = tab_a1[j])
                << std::endl;
      NT2_TEST_ULP_EQUAL( nt2::idivceil(a0,a1), r_t(nt2::ceil((1.0*a0)/a1)),0);
   }
} // end of test for signed_int_