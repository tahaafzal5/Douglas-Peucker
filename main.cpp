#include <cmath>
#include <iostream>
#include <matplot/matplot.h>

int main()
{
  double epsilon = 0;

  std::vector<double> xPoints;
  std::vector<double> yPoints;

  for (double x = 0.0; x <= 5.0; x += 0.1)
  {
    xPoints.push_back(x);
    double y = std::exp(-x) * std::cos(2 * M_PI * x);
    yPoints.push_back(y);
  }

  // Create a plot
  matplot::plot(xPoints, yPoints).get()->marker("o");

  // Show the plot
  matplot::show();

  return 0;
}