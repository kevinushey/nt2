//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_DIAG_OF_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_DIAG_OF_HPP_INCLUDED

#include <nt2/core/functions/diag_of.hpp>
#include <nt2/include/functions/enumerate.hpp>
#include <nt2/include/functions/run.hpp>
#include <nt2/sdk/meta/as_index.hpp>

namespace nt2 { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT  ( run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::diag_of_, N, nt2::container::domain>))
                              (generic_< integer_<State> >)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename boost::dispatch::meta::
            call<nt2::tag::run_ ( typename  boost::proto::result_of::
                                            child_c<A0&, 0>::type
                                , State const&, Data const&
                                )
                >::type                                           result_type;

    typedef typename meta::strip<result_type>::type               base_type;
    typedef typename meta::as_index<base_type>::type   id_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      std::size_t offset = boost::proto::child_c<1>(a0);
      return nt2::run ( boost::proto::child_c<0>(a0)
                      , nt2::enumerate<id_t>(p*offset,offset)
                      , t
                      );
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::offset_diag_of_, N, nt2::container::domain>))
                              (generic_< integer_<State> >)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename boost::dispatch::meta::
            call<nt2::tag::run_ ( typename  boost::proto::result_of::
                                            child_c<A0&, 0>::type
                                , State const&, Data const&
                                )
                >::type                                           result_type;

    typedef typename meta::strip<result_type>::type               base_type;
    typedef typename meta::as_index<base_type>::type   id_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      std::size_t offset = boost::proto::child_c<2>(a0);
      std::size_t start  = boost::proto::child_c<1>(a0);
      return nt2::run ( boost::proto::child_c<0>(a0)
                      , nt2::enumerate<id_t>(start+p*offset,offset)
                      , t
                      );
    }
  };
} }

#endif
