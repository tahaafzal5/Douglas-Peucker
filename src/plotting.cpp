#include "plotting.h"
#include <cmath>
#include <matplot/matplot.h>
#include <string>
#include <unistd.h>

Plotting::Plotting(double epsilon, double sleepDuration)
    : m_epsilon(epsilon), m_marker("."), m_sleepDuration(sleepDuration)
{
}

Plotting::~Plotting()
{
}

void Plotting::setMarker(const char* marker)
{
  m_marker = marker;
}

void Plotting::collectXPoints(std::vector<double> xPoints)
{
  m_xPointsVector.push_back(xPoints);

  std::vector<double> yPoints;
  for (const double x : xPoints)
  {
    double y = std::exp(-x) * std::cos(2 * M_PI * x);
    yPoints.push_back(y);
  }

  this->collectYPoints(yPoints);
}

void Plotting::collectYPoints(std::vector<double> yPoints)
{
  m_yPointsVector.push_back(yPoints);
}

void Plotting::plot()
{
  if (m_xPointsVector.empty() || m_yPointsVector.empty())
  {
    std::cerr << "No points\n";
    return;
  }

  if (!m_marker)
  {
    std::cerr << "No marker set\n";
    return;
  }

  for (int i = 0; i < m_xPointsVector.size(); i++)
  {
    std::string title = "Plot " + std::to_string(i);
    matplot::title(title);

    matplot::plot(m_xPointsVector.at(i), m_yPointsVector.at(i))
        .get()
        ->marker(m_marker);
    sleep(m_sleepDuration);
  }

  matplot::show();
}