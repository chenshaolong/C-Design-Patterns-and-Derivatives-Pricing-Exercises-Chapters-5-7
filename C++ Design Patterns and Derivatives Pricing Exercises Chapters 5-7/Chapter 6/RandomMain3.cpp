// C++ Design Patterns and Derivatives Pricing---Listing 6.9, page 117

/*
uses source files
    AntiThetic.cpp
    Arrays.cpp
    ConvergenceTable.cpp
    MCStatistics.cpp
    Normals.cpp
    Parameters.cpp
    ParkMiller.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random2.cpp
    SimpleMC8.cpp
    Vanilla3.cpp
*/
#include <iostream>
#include <ctime>
#include "SimpleMC8.h"
#include "ParkMiller.h"
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
using namespace std;

int main() {
    srand(time(0));
    // double time = clock();

    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

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
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);
    // VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
    // PayOffBridge(const PayOff& innerPayOff);
    // PayOff& PayOffCall::thePayOff -> PayOffBridge

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);

    AntiThetic GenTwo(generator);

    SimpleMonteCarlo6(theOption,
                      Spot,
                      VolParam,
                      rParam,
                      NumberOfPaths,
                      gathererTwo,
                      GenTwo);

    vector<vector<double>> results = gathererTwo.GetResultsSoFar();

    cout <<"For the call price the results are\n"; 
    for (unsigned long i = 0; i < results.size(); i++) {
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}