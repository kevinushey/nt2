//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_FAST_SINCOS_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_FAST_SINCOS_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>

#include <nt2/toolbox/trigonometric/function/scalar/impl/trigo.hpp>
//  MIGRATION WARNING you have to provide the file for the previous include from
//  nt2/core/numeric/function/details/scalar/impl/trigo.hpp
//  of the old nt2


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::fast_sincos_, tag::cpu_,
                             (A0),
                             (fundamental_<A0>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::fast_sincos_(tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      typedef boost::fusion::tuple<etype, etype>                   type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type res;
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      impl::trig_base < A0,radian_tag
                      , fast_tag, tag::not_simd_type
                      >::sincosa( etype(a0)
                                , boost::fusion::at_c<0>(res)
                                , boost::fusion::at_c<1>(res)
                                );
      return res;
    }

  };
} }

#endif
// modified by jt the 26/12/2010