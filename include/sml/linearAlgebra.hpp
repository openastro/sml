/*
 * Copyright (c) 2014-2022 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>

namespace sml
{

//! Compute cross-product of two 3-vectors.
/*!
 * Computes the cross-product of two 3-vectors.
 * The cross-product \f$\bar{R} = \bar{X} \times \bar{Y}\f$ is computed as
 * follows:
 *
 * \f{eqnarray*}{
 *      R_{1} &=& X_{2} * Y_{3} - X_{3} * Y{2} \\
 *      R_{2} &=& X_{3} * Y_{1} - X_{1} * Y{3} \\
 *      R_{3} &=& X_{1} * Y_{2} - X_{2} * Y{1}
 * \f}
 *
 * Note that the Vector3 type must support the following operation/functions:
 * - [] (element access operator, returning floating-point number)
 * - = (equals operator)
 * - .size() (vector length function)
 *
 * @tparam Vector3  3-Vector type
 * @param  vector1  A 3-vector
 * @param  vector2  A 3-vector
 * @return          Vector resulting from cross-product
 */
template <typename Vector3>
Vector3 cross(const Vector3& vector1, const Vector3& vector2)
{
    assert(vector1.size() == 3 && vector2.size() == 3);
    Vector3 result(3);
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return result;
}

//! Compute dot-product of two equal-length vectors.
/*!
 * Computes the dot-product (inner-product) of two vectors of length N.
 * The dot-product \f$r = \bar{X} \cdot \bar{Y}\f$ is computed as follows:
 *
 * \f[
 *      r = \sum_{i=1}^{N} X_{i} * Y_{i}
 * \f]
 *
 * Note that the Vector type must support the following operation/functions:
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @tparam Real     Real type
 * @tparam Vector   Vector type
 * @param  vector1  A vector of length N
 * @param  vector2  A vector of length N
 * @return          Scalar resulting from dot-product
 */
template <typename Real, typename Vector>
Real dot(const Vector& vector1, const Vector& vector2)
{
    assert(vector1.size() == vector2.size());
    Real result = 0.0;
    for (unsigned int i=0; i < vector1.size(); i++)
    {
        result += vector1[i] * vector2[i];
    }
    return result;
}

//! Compute squared-norm of vector.
/*!
 * Computes the square of the Euclidean norm of a vector of length N.
 * This is computed as the dot-product of the vector with itself.
 * The squared-norm \f$r\f$ of vector \f$X\f$ is computed as follows:
 *
 * \f[
 *      r = \sum_{i=1}^{N} X_{i}^{2}
 * \f]
 *
 * Note that the Vector type must support the following operation/functions:
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @sa dot
 * @tparam Real    Real type
 * @tparam Vector  Vector type
 * @param  vector  A vector of length N
 * @return         Scalar squared-norm of vector
 */
template <typename Real, typename Vector>
Real squaredNorm(const Vector& vector)
{
    return dot<Real, Vector>(vector, vector);
}

//! Compute norm of vector.
/*!
 * Computes the Euclidean norm of a vector of length N.
 * This is computed as the square-root of the dot-product of the vector with itself.
 * The norm \f$r\f$ of vector \f$X\f$ is computed as follows:
 *
 * \f[
 *      r = \sqrt{\sum_{i=1}^{N} X_{i}^{2}}
 * \f]
 *
 * Note that the Vector type must support the following operation/functions:
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @sa squaredNorm, dot
 * @tparam Real    Real type
 * @tparam Vector  Vector type
 * @param  vector  A vector of length N
 * @return         Scalar norm of vector
 */
template <typename Real, typename Vector>
Real norm(const Vector& vector)
{
    return std::sqrt(squaredNorm<Real, Vector>(vector));
}

//! Normalize vector.
/*!
 * Normalizes a vector of length N by computing the Euclidean norm of the vector and dividing by
 * the norm component-wise.
 * The result is a unit-vector.
 * A vector \f$X\f$ is normalized as follows:
 *
 * \f[
 *      \hat{\bar{X}} = \frac{\bar{X}}{|\bar{X}|}
 * \f]
 *
 * Note that the Vector type must support the following operation/functions:
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @sa norm, dot
 * @tparam Real    Real type
 * @tparam Vector  Vector type
 * @param  vector  A vector of length N
 * @return         Normalized vector
 */
template <typename Real, typename Vector>
Vector normalize(const Vector& vector)
{
    Vector normalizedVector = vector;
    Real vectorNorm = norm<Real, Vector>(vector);
    for (unsigned int i=0; i < vector.size(); i++)
    {
        normalizedVector[i] = vector[i] / vectorNorm;
    }
    return normalizedVector;
}

//! Get unit-vector in x-direction.
/*!
 * Returns unit-vector in the x-direction as column vector.
 *
 * Note that the Vector type must support the following operation/functions:
 * - constructor to create object with array of specified length
 * - [] (element access operator, returning floating-point number)
 *
 * @tparam Vector3  Type for 3-vector
 * @return          Unit-vector in x-direction
 */
template <typename Vector3>
Vector3 getXUnitVector()
{
    Vector3 xUnitVector(3);
    xUnitVector[0] = 1.0;
    xUnitVector[1] = 0.0;
    xUnitVector[2] = 0.0;
    return xUnitVector;
}

//! Get unit-vector in y-direction.
/*!
 * Returns unit-vector in the y-direction as column vector.
 *
 * Note that the Vector type must support the following operation/functions:
 * - constructor to create object with array of specified length
 * - [] (element access operator, returning floating-point number)
 *
 * @tparam Vector3  Type for 3-vector
 * @return          Unit-vector in y-direction
 */
template <typename Vector3>
Vector3 getYUnitVector()
{
    Vector3 yUnitVector(3);
    yUnitVector[0] = 0.0;
    yUnitVector[1] = 1.0;
    yUnitVector[2] = 0.0;
    return yUnitVector;
}

//! Get unit-vector in z-direction.
/*!
 * Returns unit-vector in the z-direction as column vector.
 *
 * Note that the Vector type must support the following operation/functions:
 * - constructor to create object with array of specified length
 * - [] (element access operator, returning floating-point number)
 *
 * @tparam Vector3  Type for 3-vector
 * @return          Unit-vector in z-direction
 */
template <typename Vector3>
Vector3 getZUnitVector()
{
    Vector3 zUnitVector(3);
    zUnitVector[0] = 0.0;
    zUnitVector[1] = 0.0;
    zUnitVector[2] = 1.0;
    return zUnitVector;
}

//! Multiply by scalar element-wise.
/*!
 * Multiply each element of a vector of length N by a scalar.
 *
 * Note that the Vector type must support the following operation/functions:
 * - copy constructor
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @tparam Real        Real type
 * @tparam Vector      Vector type
 * @param  vector      Vector to multiply element-wise
 * @param  multiplier  Multiplier to multiply vector element-wise
 * @return             Vector multiplied element-wise
 */
template <typename Real, typename Vector>
Vector multiply(const Vector& vector, const Real multiplier)
{
    Vector result = vector;
    for (unsigned int i=0; i < vector.size(); i++)
    {
        result[i] = multiplier * vector[i];
    }
    return result;
}

//! Add scalar element-wise.
/*!
 * Add a scalar to each element of a vector of length N.
 *
 * Note that the Vector type must support the following operation/functions:
 * - copy constructor
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @tparam Real    Real type
 * @tparam Vector  Vector type
 * @param  vector  Vector to add to element-wise
 * @param  adder   Added to multiply vector element-wise
 * @return         Vector added to element-wise
 */
template <typename Real, typename Vector>
Vector add(const Vector& vector, const Real adder)
{
    Vector result = vector;
    for (unsigned int i=0; i < vector.size(); i++)
    {
        result[i] = adder + vector[i];
    }
    return result;
}

//! Add two vectors element-wise.
/*!
 * Add two vectors of length N element-wise.
 *
 * Note that the Vector type must support the following operation/functions:
 * - copy constructor
 * - [] (element access operator, returning floating-point number)
 * - .size() (vector length function)
 *
 * @tparam Vector   Vector type
 * @param  vector1  A vector to add to element-wise
 * @param  vector2  A vector to add to element-wise
 * @return          Vector resulting from element-wise addition of two vectors
 */
template <typename Vector>
Vector add(const Vector& vector1, const Vector& vector2)
{
    assert(vector1.size() == vector2.size());
    Vector result = vector1;
    for (unsigned int i = 0; i <vector1.size(); i++)
    {
        result[i] = vector1[i] + vector2[i];
    }
    return result;
}

} // namespace sml
