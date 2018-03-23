// C++ Design Patterns and Derivatives Pricing---Listing 4.7, page 63

#include "PayOff3.h"
#include <algorithm>    // std::minmax

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_) {}

double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike, 0.0);
}

PayOff* PayOffCall::clone() const
 {
 	return new PayOffCall(*this);
 }

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_) {}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot, 0.0);
}

PayOff* PayOffPut::clone() const
 {
 	return new PayOffPut(*this);
 }