#ifndef _BEZIER_H
#define _BEZIER_H

#include "Vector2D.h"

/**
 * @struct BezierCurve
 * @brief Represents a cubic Bezier curve defined by four control points.
 *
 * The `BezierCurve` struct defines a cubic Bezier curve using four control points: p0, p1, p2, and p3.
 * It provides a method to calculate a point on the curve at a given interpolation parameter `t`.
 */
struct BezierCurve {
	Vector2D p0;
	Vector2D p1;
	Vector2D p2;
	Vector2D p3;

	/**
	 * @brief Calculates a point on the Bezier curve at a specified interpolation parameter `t`.
	 * @param t The interpolation parameter, typically in the range [0, 1], where 0 represents the start of the curve and 1 represents the end.
	 * @return The computed point on the Bezier curve at parameter `t`.
	 */
	Vector2D CalculateCurvePoint(float t) {

		float t_square = t * t;
		float t_cube = t_square * t;
		float u = 1.0f - t;
		float u_square = u * u;
		float u_cube = u_square * u;

		float second = 3.0f * u_square * t;
		float third = 3.0f * u * t_square;

		Vector2D point = (u_cube * p0) + (second * p1) + (third * p2) + (t_cube * p3);

		point.x = round(point.x);
		point.y = round(point.y);
		return point;
	}
};
#endif
