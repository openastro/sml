/*
 * Copyright (c) 2014-2022 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <catch2/catch_test_macros.hpp>

#include <vector>

#include "sml/linearAlgebra.hpp"

namespace sml
{
namespace tests
{

typedef double Real;
typedef std::vector<Real> Vector;

TEST_CASE("Test cross product function", "[cross-product]")
{
    SECTION("Test computation of cross product of unit 3-vectors")
    {
        Vector unitX(3);
        Vector unitY(3);
        Vector unitZ(3);

        unitX[0] = 1.0;
        unitX[1] = 0.0;
        unitX[2] = 0.0;

        unitY[0] = 0.0;
        unitY[1] = 1.0;
        unitY[2] = 0.0;

        unitZ[0] = 0.0;
        unitZ[1] = 0.0;
        unitZ[2] = 1.0;

        REQUIRE(cross(unitX, unitY) == unitZ);
        REQUIRE(cross(unitY, unitZ) == unitX);
        REQUIRE(cross(unitZ, unitX) == unitY);
    }

    SECTION("Test computation of cross-product of arbitrary, 3-vectors")
    {
        Vector vector1(3);
        Vector vector2(3);
        Vector result(3);

        vector1[0] = 1.342;
        vector1[1] = -3.576;
        vector1[2] = 12.113;

        vector2[0] = -0.024;
        vector2[1] = 10.125;
        vector2[2] = -9.645;

        result[0] = -88.153605;
        result[1] = 12.652878000000001;
        result[2] = 13.501926000000001;

        REQUIRE(cross(vector1, vector2) == result);
    }

    // @TODO: find a way to test assert statement in cross()

}

TEST_CASE("Test dot product function", "[dot-product]")
{
    SECTION("Test computation of dot product of equal-length zero vectors")
    {
        Vector vector(3);

        vector[0] = 0.0;
        vector[1] = 0.0;
        vector[2] = 0.0;

        REQUIRE(dot<Real>(vector, vector) == 0.0);
    }

    SECTION("Test computation of dot product of arbitrary, equal-length vectors")
    {
        Vector vector1(4);
        Vector vector2(4);

        vector1[0] = 1.234;
        vector1[1] = -2.674;
        vector1[2] = 10.812;
        vector1[3] = -12.123;

        vector2[0] = -4.119;
        vector2[1] = -3.003;
        vector2[2] = -0.048;
        vector2[3] = 17.367;

        Real result = -208.111941;

        REQUIRE(dot<Real>(vector1, vector2) == result);
    }

    // @TODO: find a way to test assert statement in dot()
}

TEST_CASE("Test squared-norm function", "[norm]")
{
    SECTION("Test computation of squared-norm of vector of zeros")
    {
        Vector vector(3);

        vector[0] = 0.0;
        vector[1] = 0.0;
        vector[2] = 0.0;

        REQUIRE(squaredNorm<Real>(vector) == 0.0);
    }

    SECTION("Test computation of squared-norm of arbitrary vector")
    {
        Vector vector(4);

        vector[0] = 1.234;
        vector[1] = -2.674;
        vector[2] = 10.812;
        vector[3] = -12.123;

        Real result = 272.53950499999996;

        REQUIRE(squaredNorm<Real>(vector) == result);
    }
}

TEST_CASE("Test norm function", "[norm]")
{
    SECTION("Test computation of norm of vector of zeros")
    {
        Vector vector(3);

        vector[0] = 0.0;
        vector[1] = 0.0;
        vector[2] = 0.0;

        REQUIRE(norm<Real>(vector) == 0.0);
    }

    SECTION("Test computation of norm of arbitrary vector")
    {
        Vector vector(4);

        vector[0] = 1.234;
        vector[1] = -2.674;
        vector[2] = 10.812;
        vector[3] = -12.123;

        Real result = 16.508770547802765;

        REQUIRE(norm<Real>(vector) == result);
    }
}

TEST_CASE("Test normalize vector function", "[norm]")
{
    SECTION("Test normalization arbitrary vector")
    {
        Vector vector(4);

        vector[0] = 1.234;
        vector[1] = -2.674;
        vector[2] = 10.812;
        vector[3] = -12.123;

        Vector result(4);
        result[0] = 0.07474814653379741;
        result[1] = -0.1619745087774508;
        result[2] = 0.6549246031794307;
        result[3] = -0.7343369371387568;

        REQUIRE(normalize<Real>(vector) == result);
    }
}

TEST_CASE("Test function that returns unit-vectors", "[unit-vector]")
{
    SECTION("Test return of unit-vector in x-direction")
    {
        Vector xUnitVector(3);

        xUnitVector[0] = 1.0;
        xUnitVector[1] = 0.0;
        xUnitVector[2] = 0.0;

        REQUIRE(getXUnitVector<Vector>() == xUnitVector);
    }

    SECTION("Test return of unit-vector in y-direction")
    {
        Vector yUnitVector(3);

        yUnitVector[0] = 0.0;
        yUnitVector[1] = 1.0;
        yUnitVector[2] = 0.0;

        REQUIRE(getYUnitVector<Vector>() == yUnitVector);
    }

    SECTION("Test return of unit-vector in z-direction")
    {
        Vector zUnitVector(3);

        zUnitVector[0] = 0.0;
        zUnitVector[1] = 0.0;
        zUnitVector[2] = 1.0;

        REQUIRE(getZUnitVector<Vector>() == zUnitVector);
    }
}

TEST_CASE("Test element-wise operations", "[element-wise]")
{
    SECTION("Multiply arbitrary vector element-wise")
    {
        Vector vector(3);
        vector[0] = 12.3;
        vector[1] = -15.4;
        vector[2] = 0.17;

        Vector result(3);

        Real multiplier = 0.0;

        SECTION("Multiply vector element-wise by 1 to yield same vector")
        {
            multiplier = 1.0;

            result = vector;

            REQUIRE(multiply(vector, multiplier) == result);
        }

        SECTION("Multiply vector element-wise by 0 to yield 0-vector")
        {
            multiplier = 0.0;

            result[0] = 0.0;
            result[1] = 0.0;
            result[2] = 0.0;

            REQUIRE(multiply(vector, multiplier) == result);
        }

        SECTION("Multiply vector element-wise by positive multiplier with magnitude greater than unity")
        {
            multiplier = 6.35;

            result[0] = 78.105;
            result[1] = -97.78999999999999;
            result[2] = 1.0795000000000001;

            REQUIRE(multiply(vector, multiplier) == result);
        }

        SECTION("Multiply vector element-wise by negative multiplier with magnitude greater than unity")
        {
            multiplier = -4.65;

            result[0] = -57.19500000000001;
            result[1] = 71.61000000000001;
            result[2] = -0.7905000000000001;

            REQUIRE(multiply(vector, multiplier) == result);
        }

        SECTION("Multiply vector element-wise by positive multiplier with magnitude less than unity")
        {
            multiplier = 0.146;

            result[0] = 1.7958;
            result[1] = -2.2483999999999997;
            result[2] = 0.024820000000000002;

            REQUIRE(multiply(vector, multiplier) == result);
        }

        SECTION("Multiply vector element-wise by negative multiplier with magnitude less than unity")
        {
            multiplier = -0.0488;

            result[0] = -0.6002400000000001;
            result[1] = 0.7515200000000001;
            result[2] = -0.008296000000000001;

            REQUIRE(multiply(vector, multiplier) == result);
        }
    }

    SECTION("Add to arbitrary vector element-wise")
    {
        Vector vector(3);
        vector[0] = 12.3;
        vector[1] = -15.4;
        vector[2] = 0.17;

        Vector result(3);

        Real adder = 0.0;

        SECTION("Add 0 to vector element-wise to yield same vector")
        {
            adder = 0.0;

            REQUIRE(add(vector, adder) == vector);
        }

        SECTION("Add positive adder to vector element-wise")
        {
            adder = 6.35;

            result[0] = 18.65;
            result[1] = -9.05;
            result[2] = 6.52;

            REQUIRE(add(vector, adder) == result);
        }

        SECTION("Add negative adder to vector element-wise")
        {
            adder = -3.64;

            result[0] = 8.66;
            result[1] = -19.04;
            result[2] = -3.47;

            REQUIRE(add(vector, adder) == result);
        }
    }

    SECTION("Add two vectors of equal length element-wise")
    {
        SECTION("Add two 0-vectors")
        {
            Vector vector(2);

            vector[0] = 0.0;
            vector[1] = 0.0;

            REQUIRE(add(vector, vector) == vector);
        }

        SECTION("Add arbitrary vector to itself")
        {
            Vector vector(2);
            Vector result(2);

            vector[0] = 2.6;
            vector[1] = -9.4;

            result[0] = 5.2;
            result[1] = -18.8;

            REQUIRE(add(vector, vector) == result);
        }

        SECTION("Add two arbitrary, equal-length vectors")
        {
            Vector vector1(2);
            Vector vector2(2);
            Vector result(2);

            vector1[0] = 2.6;
            vector1[1] = -9.4;

            vector2[0] = -0.54;
            vector2[1] = 12.3;

            result[0] = 2.06;
            result[1] = 2.9000000000000004;

            REQUIRE(add(vector1, vector2) == result);
        }

        // @TODO: find a way to test assert statement in add() for two vectors
    }

}

} // namespace tests
} // namespace sml
