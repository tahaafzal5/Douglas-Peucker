#ifndef DOUGLASPEUCKER_H
#define DOUGLASPEUCKER_H

#include "Point.h"
#include "plotting.h"
#include <vector>

class DouglasPeucker
{
public:
  DouglasPeucker(double epsilon = 0.0);
  ~DouglasPeucker();

private:
  std::vector<std::vector<Point>> m_pointsVector;
  double m_epsilon;
  Plotting* m_plotter;

  void initializeAllPoints();
  void collectPoints(const std::vector<Point>& points);
  double findFurthestDistance(const Point& firstPoint, const Point& lastPoint);
};

#endif // DOUGLASPEUCKER_H