// C++ Design Patterns and Derivatives Pricing---Exercise 7.1, page 138

#ifndef PATH_DEPENDENT_GEOMETRIC_ASIAN_H
#define PATH_DEPENDENT_GEOMETRIC_ASIAN_H
#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentGeometricAsian : public PathDependent
{
public:
	PathDependentGeometricAsian(const MJArray& LookAtTimes_, double DeliveryTime_, const PayOffBridge& ThePayOff_);
	virtual ~PathDependentGeometricAsian() {}

	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlowTimes() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
	virtual PathDependent* clone() const;
private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;
};

#endif