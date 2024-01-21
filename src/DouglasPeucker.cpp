#include "DouglasPeucker.h"
#include "plotting.h"
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

double DouglasPeucker::findFurthestDistance(const Point& firstPoint,
                                            const Point& lastPoint)
{
  double furthestDistance = 0.0;

  //   for (const auto& point : m_allPoints)
  //   {
  //   }

  return furthestDistance;
}