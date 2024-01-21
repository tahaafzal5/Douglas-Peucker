#include "plotting.h"
#include <cmath>
#include <matplot/matplot.h>

Plotting::Plotting(double epsilon) : m_epsilon(epsilon), m_marker(".")
{
  for (double x = 0.0; x <= 5.0; x += 0.1)
  {
    m_xPoints.push_back(x);

    double y = std::exp(-x) * std::cos(2 * M_PI * x);
    m_yPoints.push_back(y);
  }
}

// Destructor implementation
Plotting::~Plotting()
{
}

void Plotting::setMarker(const char* marker)
{
  m_marker = marker;
}

void Plotting::plot()
{
  if (m_xPoints.empty() || m_yPoints.empty())
  {
    std::cerr << "No points\n";
    return;
  }

  if (!m_marker)
  {
    std::cerr << "No marker set\n";
    return;
  }

  matplot::plot(m_xPoints, m_yPoints).get()->marker(m_marker);

  matplot::show();
}