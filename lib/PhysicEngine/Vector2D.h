#pragma once

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

#include <iostream>

/**
 * @class Vector2D
 * @brief Represents a 2D vector with x and y components.
 *
 * The `Vector2D` class provides functionalities for 2D vector operations, including addition, subtraction,
 * multiplication, division, rotation, and more.
 */
class Vector2D {

public:

	float x, y;

	/**
	* @brief Default constructor for the Vector2D class.
	*
	* Initializes both x and y components to 0.
	*/
	Vector2D();

	/**
	 * @brief Parameterized constructor for the Vector2D class.
	 * @param x The initial x-component of the vector.
	 * @param y The initial y-component of the vector.
	 *
	 * Initializes the vector with specified x and y values.
	 */
	Vector2D(float x, float y);

	/**
	 * @brief Adds another vector to this vector.
	 * @param vector The vector to be added.
	 * @return A reference to the modified vector.
	 *
	 * Adds the components of the given vector to this vector.
	 */
	Vector2D& Add(const Vector2D& vector);

	/**
	 * @brief Subtracts another vector from this vector.
	 * @param vector The vector to be subtracted.
	 * @return A reference to the modified vector.
	 *
	 * Subtracts the components of the given vector from this vector.
	 */
	Vector2D& Subtract(const Vector2D& vector);

	/**
	 * @brief Multiplies this vector by another vector element-wise.
	 * @param vector The vector to be multiplied with.
	 * @return A reference to the modified vector.
	 *
	 * Multiplies the components of this vector by the corresponding components of the given vector.
	 */
	Vector2D& Multiply(const Vector2D& vector);

	/**
	* @brief Divides this vector by another vector element-wise.
	* @param vector The vector to be divided by.
	* @return A reference to the modified vector.
	*
	* Divides the components of this vector by the corresponding components of the given vector.
	*/
	Vector2D& Divide(const Vector2D& vector);

	/**
	 * @brief Overloaded addition operator for vector addition.
	 * @param v1 The first vector.
	 * @param v2 The second vector to be added.
	 * @return The result of adding v1 and v2.
	 */
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);

	/**
	 * @brief Overloaded subtraction operator for vector subtraction.
	 * @param v1 The first vector.
	 * @param v2 The second vector to be subtracted.
	 * @return The result of subtracting v2 from v1.
	 */
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);

	/**
	* @brief Overloaded multiplication operator for vector element-wise multiplication.
	* @param v1 The first vector.
	* @param v2 The second vector for element-wise multiplication.
	* @return The result of element-wise multiplication of v1 and v2.
	*/
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);

	/**
	 * @brief Overloaded multiplication operator for scalar-vector multiplication.
	 * @param v1 The scalar value.
	 * @param v2 The vector to be multiplied.
	 * @return The result of multiplying the vector v2 by the scalar v1.
	 */
	friend Vector2D& operator*(float& v1, const Vector2D& v2);

	/**
	* @brief Overloaded division operator for vector element-wise division.
	* @param v1 The first vector.
	* @param v2 The second vector for element-wise division.
	* @return The result of element-wise division of v1 by v2.
	*/
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	/**
	 * @brief Overloaded compound addition assignment operator.
	 * @param vector The vector to be added.
	 * @return A reference to the modified vector.
	 *
	 * Adds the components of the given vector to this vector.
	 */
	Vector2D& operator+=(const Vector2D& vector);

	/**
	 * @brief Overloaded compound subtraction assignment operator.
	 * @param vector The vector to be subtracted.
	 * @return A reference to the modified vector.
	 *
	 * Subtracts the components of the given vector from this vector.
	 */
	Vector2D& operator-=(const Vector2D& vector);

	/**
	 * @brief Overloaded compound multiplication assignment operator.
	 * @param vector The vector to be multiplied.
	 * @return A reference to the modified vector.
	 *
	 * Multiplies the components of this vector by the corresponding components of the given vector.
	 */
	Vector2D& operator*=(const Vector2D& vector);

	/**
	* @brief Overloaded compound division assignment operator.
	* @param vector The vector to be divided by.
	* @return A reference to the modified vector.
	*
	* Divides the components of this vector by the corresponding components of the given vector.
	*/
	Vector2D& operator/=(const Vector2D& vector);

	/**
	 * @brief Overloaded multiplication operator for scalar-vector multiplication.
	 * @param i The scalar value.
	 * @return A reference to the modified vector.
	 *
	 * Multiplies this vector by the scalar value `i`.
	 */
	Vector2D& operator*(const int& i);

	/**
	 * @brief Sets the components of the vector to zero.
	 * @return A reference to the modified vector.
	 *
	 * Resets both the x and y components of the vector to zero.
	 */
	Vector2D& Zero();

	/**
	 * @brief Rotates a vector by a given angle.
	 * @param vec The vector to be rotated.
	 * @param angle The angle of rotation in degrees.
	 * @return The rotated vector.
	 *
	 * Rotates the given vector by the specified angle in degrees and returns the result.
	 */
	static Vector2D RotateVector(Vector2D& vec, float angle);

	/**
	 * @brief Overloaded output stream operator for vector output.
	 * @param stream The output stream.
	 * @param vector The vector to be output.
	 * @return The output stream containing the vector components.
	 */
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vector);
};