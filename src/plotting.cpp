#include "plotting.h"
#include <cmath>
#include <matplot/matplot.h>
#include <unistd.h>

Plotting::Plotting(double sleepDuration)
    : m_marker("."), m_sleepDuration(sleepDuration)
{
  matplot::axis({0, 5, -1, 1});
  matplot::hold(true);
}

Plotting::~Plotting()
{
}

void Plotting::setMarker(const char* marker)
{
  m_marker = marker;
}

void Plotting::plot(const std::vector<Point>& pointsVector)
{
  if (!m_marker)
  {
    std::cerr << "No marker set\n";
    return;
  }

  std::vector<double> xValues, yValues;
  for (const auto& point : pointsVector)
  {
    xValues.push_back(point.x);
    yValues.push_back(point.y);
  }

  std::string title = "Plot " + std::to_string(0);
  matplot::title(title);
  this->printPointCount(pointsVector);
  matplot::plot(xValues, yValues).get()->marker(m_marker);
  sleep(m_sleepDuration);

  matplot::show();
}

void Plotting::printPointCount(const std::vector<Point>& pointsVector)
{
  printf("This plot has %d points\n", pointsVector.size());
}