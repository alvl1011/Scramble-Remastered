#ifndef _BEZIERPATH_H
#define _BEZIERPATH_H

#include "Bezier.h"
#include <vector>

/**
 * @class BezierPath
 * @brief Represents a path defined by a sequence of Bezier curves.
 *
 * The `BezierPath` class allows you to create and manage a path by specifying a sequence of Bezier curves.
 * You can add individual curves to the path and sample points along the path for rendering or other purposes.
 */
class BezierPath {

private:

	std::vector<BezierCurve> mCurves;
	std::vector<int> mSamples;

public:

	BezierPath();
	~BezierPath();

	/**
	 * @brief Adds a Bezier curve to the path with a specified number of samples.
	 * @param curve The Bezier curve to add to the path.
	 * @param samples The number of samples to take along the curve when sampling points.
	 */
	void AddCurve(BezierCurve curve, int samples);

	/**
	 * @brief Samples points along the entire path and stores them in a vector.
	 * @param sampledPath A pointer to a vector where the sampled points will be stored.
	 *
	 * This method samples points along each curve in the path and appends them to the provided vector.
	 */
	void Sample(std::vector<Vector2D>* sampledPath);

};
#endif
