/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#ifndef SML_BASIC_FUNCTIONS_HPP
#define SML_BASIC_FUNCTIONS_HPP

#include <cmath>

#include <catch.hpp>

#include <SML/constants.hpp>

namespace sml
{

//! Compute modulo.
/*!
 * Computes the remainder of division of one real number by another. The remainder is in the range 
 * [ 0, divisor ).
 *
 * The modulo computation is based on the mathematical definition of congruence, which is 
 * different from the implementation of std::fmod() in the cmath standard library. For a 
 * description of congruence see: http://mathworld.wolfram.com/Congruence.html.
 *
 * @tparam Real Real type 
 * @param  dividend Number to be divided.
 * @param  divisor Number that divides dividend
 * @return Remainder of division of dividend by divisor
 */
template< typename Real >
Real computeModulo( const Real dividend, const Real divisor )
{
    return dividend - divisor * std::floor( dividend / divisor );
}

//! Convert angle in radians to degrees.
/*!
 * Converts angle given in radians to degrees using the following equation:
 *
 * \f[
 *      \theta_{deg} = \theta_{rad} * 180
 * \f]
 *
 * @param  angleInRadians Angle in radians
 * @return                Angle in degrees
 */
template < typename Real >
Real convertRadiansToDegrees( const Real angleInRadians )
{ 
    return angleInRadians / SML_PI * 180.0; 
}

} // namespace sml

#endif // SML_BASIC_FUNCTIONS_HPP
