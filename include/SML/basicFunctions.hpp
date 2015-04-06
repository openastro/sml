/*
 * Copyright (c) 2014-2015 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#ifndef SML_BASIC_FUNCTIONS_HPP
#define SML_BASIC_FUNCTIONS_HPP

#include <cmath>

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
 *      \theta_{deg} = \theta_{rad} * \frac{180}{\pi}
 * \f]
 *
 * @tparam Real Real type
 * @param  angleInRadians Angle in radians
 * @return                Angle in degrees
 */
template < typename Real >
Real convertRadiansToDegrees( const Real angleInRadians )
{
    return angleInRadians / SML_PI * 180.0;
}

//! Convert angle in degrees to radians.
/*!
 * Converts angle given in degrees to radians using the following equation:
 *
 * \f[
 *      \theta_{rad} = \theta_{deg} * \frac{\pi}{180}
 * \f]
 *
 * @tparam Real Real type
 * @param  angleInDegrees Angle in degrees
 * @return                Angle in radians
 */
template < typename Real >
Real convertDegreesToRadians( const Real angleInDegrees )
{
    return angleInDegrees * SML_PI / 180.0;
}

} // namespace sml

#endif // SML_BASIC_FUNCTIONS_HPP
