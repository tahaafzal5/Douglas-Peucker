#include "plotting.h"
#include <iostream>
#include <math.h>

int main()
{
  Plotting plotting;

  std::vector<double> xPoints;
  for (double x = 0.0; x <= 5.0; x += 0.01)
  {
    xPoints.push_back(x);
  }
  plotting.collectXPoints(xPoints);

  // xPoints.clear();
  // for (double x = 0.0; x <= 5.0; x += 1)
  // {
  //   xPoints.push_back(x);
  // }
  // plotting.collectXPoints(xPoints);

  plotting.plot();

  return 0;
}