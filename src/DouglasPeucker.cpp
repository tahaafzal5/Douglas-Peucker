#include "DouglasPeucker.h"
#include "plotting.h"
#include <iostream>
#include <math.h>

#include <vector>

DouglasPeucker::DouglasPeucker(double epsilon) : m_epsilon(epsilon)
{
  m_plotter = new Plotting();

  initializeAllPoints();

  std::vector<Point> rdpPoints;
  calculate(0, m_pointsVector.size() - 1, m_pointsVector, rdpPoints);

  m_plotter->plot(rdpPoints);
};

DouglasPeucker::~DouglasPeucker()
{
  delete m_plotter;
};

void DouglasPeucker::initializeAllPoints()
{
  for (double x = 0.0; x <= 5.0; x += 0.01)
  {
    double y = std::exp(-x) * std::cos(2 * M_PI * x);

    m_pointsVector.push_back({x, y});
  }
}

void DouglasPeucker::calculate(int startIndex, int endIndex,
                               const std::vector<Point>& allPoints,
                               std::vector<Point>& rdpPoints)
{
  int nextIndex = findFurthestPointIndex(allPoints, startIndex, endIndex);

  rdpPoints.push_back(allPoints.at(startIndex));

  if (nextIndex > 0)
  {
    if (startIndex != nextIndex)
    {
      calculate(startIndex, nextIndex, allPoints, rdpPoints);
    }

    rdpPoints.push_back(allPoints.at(nextIndex));

    if (endIndex != nextIndex)
    {
      calculate(nextIndex, endIndex, allPoints, rdpPoints);
    }
  }

  rdpPoints.push_back(allPoints.at(endIndex));
}

int DouglasPeucker::findFurthestPointIndex(const std::vector<Point>& allPoints,
                                           const int a, const int b)
{
  double furthestDistance = -1.0;
  int furthestPointIndex = -1;

  Point start = allPoints.at(a);
  Point end = allPoints.at(b);

  for (int i = a + 1; i < b; i++)
  {
    Point currentPoint = allPoints.at(i);
    double distance = distanceBetweenPointAndLine(currentPoint, start, end);
    if (distance > furthestDistance)
    {
      furthestDistance = distance;
      furthestPointIndex = i;
    }
  }

  if (furthestDistance > m_epsilon)
  {
    return furthestPointIndex;
  }
  else
  {
    return -1;
  }
}

double DouglasPeucker::distanceBetweenPointAndLine(Point point,
                                                   Point linePoint1,
                                                   Point linePoint2)
{
  double numerator =
      std::fabs((linePoint2.x - linePoint1.x) * (linePoint1.y - point.y) -
                (linePoint1.x - point.x) * (linePoint2.y - linePoint1.y));
  double denominator = sqrt(pow((linePoint2.x - linePoint1.x), 2) +
                            pow((linePoint2.y - linePoint1.y), 2));

  return numerator / denominator;
}