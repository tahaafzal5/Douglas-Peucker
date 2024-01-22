#ifndef DOUGLASPEUCKER_H
#define DOUGLASPEUCKER_H

#include "Point.h"
#include "plotting.h"
#include <vector>

class DouglasPeucker
{
public:
  DouglasPeucker(double epsilon = 0.01);
  ~DouglasPeucker();

private:
  std::vector<Point> m_pointsVector;
  double m_epsilon;
  Plotting* m_plotter;

  void initializeAllPoints();
  int findFurthestPointIndex(const std::vector<Point>& allPoints, const int a,
                             const int b);
  double distanceBetweenPointAndLine(Point point, Point linePoint1,
                                     Point linePoint2);
  void calculate(int startIndex, int endIndex,
                 const std::vector<Point>& allPoints,
                 std::vector<Point>& rdpPoints);
};

#endif // DOUGLASPEUCKER_H