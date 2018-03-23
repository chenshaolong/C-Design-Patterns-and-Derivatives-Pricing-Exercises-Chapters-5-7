// C++ Design Patterns and Derivatives Pricing---Exercise 5.5, page 100

/*
Write a template class that implements a reference counted wrapper.

This will be similar to the wrapper class but instead of making a clone of the inner object when the wrapper
is copied, an internal counter is increased and the inner object is shared.

When a copy is destroyed, the inner counter is decremented.

When the inner counter reaches zero, the object is destroyed.

Note that both the counter and the inner object will be shared across copies of the object.
*/

#include <iostream>
#include "PayOff3.h"
#include "ref_count_wrapper.h"
using namespace std;

// requires PayOff3.cpp

int main()
{
	//test shared wrapper class by emza0114

	{
		double Strike = 100.0;

		PayOffCall callPayOff(Strike);

		SharedWrapper<PayOff> payoff1(callPayOff);
		SharedWrapper<PayOff> payoff2(payoff1);
		SharedWrapper<PayOff> payoff3 = callPayOff;

		cout << "1st instance for call option with Spot = 100 : ";
		cout << payoff1->operator()(100.0) << endl;
		cout << "2nd instance for call option with Spot = 120 : ";
		cout << payoff2->operator()(120.0) << endl;
		cout << "3rd instance for call option with Spot = 80 : ";
		cout << payoff3->operator()(80.0) << endl;

		PayOffPut putPayOff(Strike);

		SharedWrapper<PayOff> payoff4(putPayOff);
		SharedWrapper<PayOff> payoff5(payoff4);
		SharedWrapper<PayOff> payoff6 = payoff5;

		cout << "1st instance for put option with Spot = 100 : ";
		cout << payoff4->operator()(100.0) << endl;
		cout << "2nd instance for put option with Spot = 110 : ";
		cout << payoff5->operator()(110.0) << endl;
		cout << "3rd instance for put option with Spot = 90 : ";
		cout << payoff6->operator()(90.0) << endl;
	}
	cout << "Done.\n";
	return 0;
}