// C++ Design Patterns and Derivatives Pricing---Listing 7.9, page 135

/*
uses source files 
    AntiThetic.cpp
    Arrays.cpp,  
    ConvergenceTable.cpp, 
    ExoticBSEngine.cpp
    ExoticEngine
    MCStatistics.cpp
    Normals.cpp
    Parameters.cpp,
    ParkMiller.cpp,
    PathDependent.cpp
    PathDependentAsian.cpp
    PayOff3.cpp, 
    PayOffBridge.cpp,
    Random2.cpp,
  */
#include "ParkMiller.h"
#include <iostream>
using namespace std;
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"

int main()
{
    srand(time(0));
    // double time = clock();

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r;
    double d;
	unsigned long NumberOfPaths;
    unsigned NumberOfDates;

	cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter Strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "d: ";
    cin >> d;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;
    cout << "Number of dates: ";
    cin >> NumberOfDates;

    PayOffCall thePayOff(Strike);


    MJArray times(NumberOfDates);

    for (unsigned long i = 0; i < NumberOfDates; i++)
        times[i] = (i + 1.0) * Expiry / NumberOfDates;

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    PathDependentAsian theOption(times, Expiry, thePayOff);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

   
    RandomParkMiller generator(NumberOfDates);
    
    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);

    vector<vector<double> > results  =gathererTwo.GetResultsSoFar();


	cout <<"\nFor the Asian call price the results are \n";
  
    {
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }}

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}
