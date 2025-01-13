/*
 * Copyright (c) 2014-2025 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <map>

#include <catch2/catch_test_macros.hpp>

#include "sml/lagrangeInterpolator.hpp"

namespace sml
{
namespace tests
{

typedef double Real;
typedef std::map<Real,Real> FunctionDataMap;

TEST_CASE("Test langrange interpolator function", "[lagrange-interpolator]")
{
    SECTION("Test using case 1 from tutorialspoint.com")
    {
        // Source: https://www.tutorialspoint.com/lagrange-s-interpolation-in-cplusplus
        const FunctionDataMap functionDataMap = {{0.0,3.0}, {1.0,2.0}, {6.0,9.0}, {10.0,17.0}};
        const Real independentVariable = 3.0;
        REQUIRE(lagrangeInterpolate(functionDataMap, independentVariable) == 3.0);
    }

    SECTION("Test using case 2 from tutorialspoint.com")
    {
        // Source: https://www.tutorialspoint.com/Lagrange-Interpolation
        // Result is given approximately as 34.328125
        // Test is based on floating-point precise result computated using lagrangeInterpolate()
        const FunctionDataMap functionDataMap = {{0.0,0.0},
                                                 {1.0,1.0},
                                                 {2.0,8.0},
                                                 {3.0,27.0},
                                                 {4.0,64.0},
                                                 {5.0,125.0},
                                                 {6.0,216.0}};
        const Real independentVariable = 3.25;
        REQUIRE(lagrangeInterpolate(functionDataMap, independentVariable) == 34.328124999999993);
    }

    SECTION("Test using case from geeksforgeeks.org")
    {
        // Source: https://www.geeksforgeeks.org/lagranges-interpolation
        const FunctionDataMap functionDataMap = {{0.0,2.0}, {1.0,3.0}, {2.0,12.0}, {5.0,147.0}};
        const Real independentVariable = 3.0;
        REQUIRE(lagrangeInterpolate(functionDataMap, independentVariable) == 35.0);
    }
}

} // namespace tests
} // namespace sml