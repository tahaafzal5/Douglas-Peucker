#ifndef PLOTTING_H
#define PLOTTING_H

#include <string>
#include <vector>

class Plotting
{
public:
  // Constructor
  Plotting(double epsilon = 0, double sleepDuration = 1.0);
  void setMarker(const char* marker);
  void plot();
  void collectXPoints(std::vector<double> xPoints);

  // Destructor
  ~Plotting();

private:
  std::vector<std::vector<double>> m_xPointsVector;
  std::vector<std::vector<double>> m_yPointsVector;
  double m_epsilon;
  const char* m_marker;
  double m_sleepDuration;

  void collectYPoints(std::vector<double> yPoints);
};

#endif // PLOTTING_H