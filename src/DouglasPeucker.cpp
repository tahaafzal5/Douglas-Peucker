#include "DouglasPeucker.h"
#include "plotting.h"
#include <iostream>
#include <math.h>

#include <vector>

DouglasPeucker::DouglasPeucker(double epsilon) : m_epsilon(epsilon)
{
  m_plotter = new Plotting();

  initializeAllPoints();
  m_plotter->plot(m_pointsVector);
};

DouglasPeucker::~DouglasPeucker()
{
  delete m_plotter;
};

void DouglasPeucker::initializeAllPoints()
{
  std::vector<Point> points;

  for (double x = 0.0; x <= 5.0; x += 0.01)
  {
    Point point;
    double y = std::exp(-x) * std::cos(2 * M_PI * x);

    point.x = x;
    point.y = y;

    points.push_back(point);
  }
  this->collectPoints(points);
}

void DouglasPeucker::collectPoints(const std::vector<Point>& points)
{
  m_pointsVector.push_back(points);
}

double DouglasPeucker::findFurthestDistance(
    const std::vector<std::vector<Point>>& allPoints, const Point& firstPoint,
    const Point& lastPoint)
{
  double furthestDistance = -1.0;

  for (const auto& point : allPoints)
  {
  }

  return furthestDistance;
}

double DouglasPeucker::distanceBetweenPointAndLine(Point point,
                                                   Point linePoint1,
                                                   Point linePoint2)
{
  double numerator =
      std::abs((linePoint2.x - linePoint1.x) * (linePoint1.y - point.y) -
               (linePoint1.x - point.x) * (linePoint2.y - linePoint1.y));
  double denominator = sqrt(pow((linePoint2.x - linePoint1.x), 2) +
                            pow((linePoint2.y - linePoint1.y), 2));

  return numerator / denominator;
}