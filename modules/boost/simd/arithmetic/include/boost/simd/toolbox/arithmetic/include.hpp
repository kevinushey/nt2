//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_INCLUDE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_INCLUDE_HPP_INCLUDED
#include <boost/simd/sdk/simd/preprocessor/include.hpp>

#define BOOST_SIMD_ARITHMETIC_BASE() boost/simd/toolbox/arithmetic/functions/scalar/
#define BOOST_SIMD_ARITHMETIC_RELATIVE() boost/simd/toolbox/arithmetic/functions/

#define BOOST_SIMD_ARITHMETIC_INCLUDE(F) BOOST_SIMD_RELATIVE_INCLUDE(BOOST_SIMD_ARITHMETIC_RELATIVE, F)


#include <boost/simd/toolbox/constant/include/true_false.hpp>

#endif
