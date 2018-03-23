// C++ Design Patterns and Derivatives Pricing---Listing 5.3, page 87

#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H
#include "Vanilla3.h"
#include "Parameters.h"
#include "MCStatistics.h"

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer);

#endif