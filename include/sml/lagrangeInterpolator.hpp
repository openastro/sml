/*
 * Copyright (c) 2014-2022 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#pragma once

#include <iostream>

namespace sml
{

//! Compute Lagrange interpolation.
/*!
 * Computes Lagrange interpolation polynomial to obtain y-value for a specified x value, given a
 * function described by a collection of N non-evenly distributed (x,y) pairs.
 *
 * Note that this implementation doesn't account for interpolation at boundaries. For the best
 * results, the x-value to interpolate at should be in the center of the x-data.
 *
 * See Wolfram MathWorld for more background information:
 * https://mathworld.wolfram.com/LagrangeInterpolatingPolynomial.html
 *
 * @tparam Real          Floating-point type
 * @tparam FunctionData  Container type with (x,y) pairs describing function
 * @param  functionData  A collection of N (x,y) pairs to describe a function
 * @param  x             x-value to interpolate at
 * @return               Interpolated y-value
 */
template <typename Real, typename FunctionData>
Real lagrangeInterpolate(const FunctionData& functionData, const Real x)
{
    Real result = 0.0;
    for(auto& pair : functionData)
    {
        Real y = pair.second;
        for(auto& innerPair : functionData)
        {
            if (innerPair != pair)
            {
                Real multiplier = (x - innerPair.first)
                                  / (pair.first - innerPair.first);
                y = y * multiplier;
            }
        }
        result = result + y;
    }
    return result;
}

}