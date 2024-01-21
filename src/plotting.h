#ifndef PLOTTING_H
#define PLOTTING_H

#include <string>
#include <vector>

class Plotting
{
public:
  // Constructor
  Plotting(double epsilon = 0);
  void setMarker(const char* marker);
  void plot();

  // Destructor
  ~Plotting();

private:
  std::vector<double> m_xPoints;
  std::vector<double> m_yPoints;
  double m_epsilon = 0.0;
  const char* m_marker;
};

#endif // PLOTTING_H