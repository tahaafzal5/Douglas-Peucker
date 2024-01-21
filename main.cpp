#include <iostream>
#include <matplot/matplot.h>

int main()
{
  // Define data points
  std::vector<double> x = {1, 2, 3, 4, 5};
  std::vector<double> y = {2, 4, 1, 3, 5};

  // Create a plot
  matplot::plot(x, y);

  // Show the plot
  matplot::show();

  return 0;
}