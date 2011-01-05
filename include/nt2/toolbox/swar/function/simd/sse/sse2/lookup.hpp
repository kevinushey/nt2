//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_SSE2_LOOKUP_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_SSE2_LOOKUP_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/meta/strip.hpp>

#include <nt2/include/functions/at.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/include/functions/store.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::lookup_, tag::cpu_,
                         (A0),
                         ((simd_<arithmetic_<A0>,tag::sse_>))
                         ((simd_<arithmetic_<A0>,tag::sse_>))
                        );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::lookup_(tag::simd_(tag::arithmetic_, tag::sse_),
                           tag::simd_(tag::arithmetic_, tag::sse_)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
      : meta::strip<A0>{};//


    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::scalar_of<A0>::type sA0;
      aligned::array < sA0,meta::cardinal_of<A0>::value,16/*NT2_SIMD_BYTE*/ > tmp, tmp1;
      nt2::store<A0>(a0, tmp.begin(), 0);

      for(int i=0; i < meta::cardinal_of<A0>::value; i++) { tmp1[i] = tmp[a1[i]]; }// TODO unroll
      return nt2::load<A0>(tmp1.begin(), 0);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is types64_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::lookup_, tag::cpu_,
                         (A0),
                         ((simd_<types64_<A0>,tag::sse_>))
                         ((simd_<types64_<A0>,tag::sse_>))
                        );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::lookup_(tag::simd_(tag::types64_, tag::sse_),
                           tag::simd_(tag::types64_, tag::sse_)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
      : meta::strip<A0>{};//


    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_real<A0>::type real_type;
      const int32_t i =  NT2_SH2(at<0>(a1), at<1>(a1))&0x3;
      //            std::cout << "---- " << i << std::endl;
      switch(i)
      {
        NT2_CASE_4( A0, _mm_shuffle_pd, simd::native_cast<real_type>(a0), simd::native_cast<real_type>(a0));
      }
    }
  };
} }

#endif
// modified by jt the 04/01/2011