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
  std::vector<Point> m_pointsVector;
  double m_epsilon;
  Plotting* m_plotter;

  void initializeAllPoints();
  double calculate(const std::vector<Point>& allPoints, const int a,
                   const int b);
  double distanceBetweenPointAndLine(Point point, Point linePoint1,
                                     Point linePoint2);
};

#endif // DOUGLASPEUCKER_H