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
  for (double x = 0.0; x <= 5.0; x += 0.01)
  {
    Point point;
    double y = std::exp(-x) * std::cos(2 * M_PI * x);

    point.x = x;
    point.y = y;

    m_pointsVector.push_back(point);
  }
}

double DouglasPeucker::calculate(const std::vector<Point>& allPoints,
                                 const int a, const int b)
{
  double furthestDistance = -1.0;

  //   Point start = allPoints.at(a);
  //   Point end = allPoints.at(b);

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