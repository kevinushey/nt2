//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <nt2/table.hpp>
#include <nt2/include/functions/issquare.hpp>
#include <nt2/include/functions/ones.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>

NT2_TEST_CASE( fundamental_issquare )
{
  NT2_TEST( nt2::issquare('e') );
  NT2_TEST( nt2::issquare(1)   );
  NT2_TEST( nt2::issquare(1.)  );
  NT2_TEST( nt2::issquare(1.f) );
}

NT2_TEST_CASE( container_issquare )
{
  NT2_TEST( nt2::issquare( nt2::ones(4) )      );
  NT2_TEST( nt2::issquare( nt2::ones(4,4))      );
  NT2_TEST( !nt2::issquare( nt2::ones(4,1,1))   );
  NT2_TEST( !nt2::issquare( nt2::ones(4,1,4,1)) );
  NT2_TEST( !nt2::issquare( nt2::ones(4,1,1,4)) );

  NT2_TEST( !nt2::issquare( nt2::ones(2,3))     );
  NT2_TEST( !nt2::issquare( nt2::ones(3,1,2))   );
  NT2_TEST( !nt2::issquare( nt2::ones(3,3,1,9)) );
}
