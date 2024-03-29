#ifndef PLOTTING_H
#define PLOTTING_H

#include "Point.h"
#include <vector>

class Plotting
{
public:
  // Constructor
  Plotting(double sleepDuration = 1.0);
  void setMarker(const char* marker);
  void plot(const std::vector<Point>& pointsVector);
  // Destructor
  ~Plotting();

private:
  const char* m_marker;
  double m_sleepDuration;

  void printPointCount(const std::vector<Point>& pointsVector);
};

#endif // PLOTTING_H