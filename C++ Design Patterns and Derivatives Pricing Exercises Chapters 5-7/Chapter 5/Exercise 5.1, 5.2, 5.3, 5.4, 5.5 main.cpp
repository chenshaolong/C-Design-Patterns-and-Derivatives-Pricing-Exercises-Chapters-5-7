// C++ Design Patterns and Derivatives Pricing---Exercise 5.1, 5.2, 5.3, 5.4, 5.5, page 99

/*
Exercise 5.1 Write a statistics gathering class 
that computes the first four moments of a sample.

Exercise 5.2 Write a statistics gathering class 
that computes the value at risk of a sample.

Exercise 5.3 Write a statistics gathering class 
that allows the computation of several statistics via inputted classes.

Exercise 5.4 Use the strategy pattern to allow the user to specify 
termination conditions for the Monte Carlo, e.g., time spent or paths done.

Exercise 5.5 Write a terminator class that causes termination when 
either of two inner terminator classes specifies termination.
*/

#include<iostream>
#include <cmath>
#include <vector>
#include "Random1.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "Terminator.h"
#include "Format.h"  // formatting stuff, from C++ Primer Plus(6th Edition)-Stephen Prata, page 765 and 767
using namespace std;

int main(){
	Terminator terminator;

	while (!terminator.isTerminated()) {
		unsigned long NumberOfPaths;

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\nNumber of paths: ";
		cin >> NumberOfPaths;

		StatisticsMean gatherer_mean;

		//exercice 5.1
		StatisticsMoments4 gatherer_m4;

		//exercice 5.2
		ValueAtRisk gatherer_var(0.05);

		//exercice 5.3
		//With current setup cannot use m4 class. Dimensions mistach
		vector<Wrapper<StatisticsMC>> stat_vec;
		stat_vec.resize(2);
		stat_vec[0] = gatherer_mean;
		stat_vec[1] = gatherer_var;
		StatsGatherer gatherer(stat_vec);

		//Generate convergence tables
		ConvergenceTable gathererOne(gatherer_m4);
		ConvergenceTable gathererTwo(gatherer);

		for (unsigned long i = 0; i < NumberOfPaths; i++)
		{
			terminator.getPath().IncrementPath();
			double thisGaussian = GetOneGaussianByBoxMuller();
			gathererOne.DumpOneResult(thisGaussian);
			gathererTwo.DumpOneResult(thisGaussian);
		}

		vector<vector<double> > results1 = gathererOne.GetResultsSoFar();
		vector<vector<double> > results2 = gathererTwo.GetResultsSoFar();

		// set up format
		Formatting format;

        if (terminator.isTerminated()) break;
		cout << "\nconvergence table 1 results: \n";
		cout << "m1\t\t m2\t\t m3\t\t m4\t\t path\n";

		for (unsigned long i = 0; i < results1.size() && !terminator.isTerminated(); i++)
		{
			for (unsigned long j = 0; j < results1[i].size() && !terminator.isTerminated(); j++)
				cout << results1[i][j] << "\t ";

			cout << "\n";
			// if (time.isTimeUp()) break;
		}

		if (terminator.isTerminated()) break;
		cout << "\nconvergenc table 2 results: \n";
		cout << "mean\t\t var\t\t path\n";

		for (unsigned long i = 0; i < results2.size() && !terminator.isTerminated(); i++)
		{
			for (unsigned long j = 0; j < results2[i].size() && !terminator.isTerminated(); j++)
				cout << results2[i][j] << "\t ";

			cout << "\n";
			//if (time.isTimeUp()) break;
		}

		if (terminator.isTerminated()) break;
	    // restore format
		format.restore();
		cout <<"Elapsed time = " << terminator.getTime().elapsedTime() << "s\n";
		cout <<"Paths done = " << terminator.getPath().getPathDone() << "s\n";
	}
    
    if (terminator.getTime().isTimeUp())
		cout <<"Terminated reason: Time's up! Total elapsed time = " << terminator.getTime().elapsedTime() << endl;
	else //if (terminator.getPath().isPathOut())
		cout <<"Terminated reason: Paths exceed the limit! Total paths done = " << terminator.getPath().getPathDone() << endl;

    cout << "Done.\n";
	return 0;
}