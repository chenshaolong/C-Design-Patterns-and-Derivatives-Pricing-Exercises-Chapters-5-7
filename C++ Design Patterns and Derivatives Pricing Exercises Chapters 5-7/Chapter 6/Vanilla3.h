// C++ Design Patterns and Derivatives Pricing---Listing 4.15, page 73

#ifndef VANILLA_3_H
#define VANILLA_3_H
#include "PayOffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);

    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
private:
	double Expiry;
	PayOffBridge ThePayOff;
};

#endif