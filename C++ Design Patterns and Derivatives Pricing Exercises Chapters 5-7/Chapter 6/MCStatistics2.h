// C++ Design Patterns and Derivatives Pricing---Exercise 5.1, 5.2, 5.3, page 99

#ifndef EXERCISE_STATISTICS_H
#define EXERCISE_STATISTICS_H

#include <vector>
#include "wrapper.h"
#include "MCStatistics.h"

//Exercice 5.1
class StatisticsMoments4 : public StatisticsMC
{
public:
    StatisticsMoments4();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    double RunningSum1;
    double RunningSum2;
    double RunningSum3;
    double RunningSum4;
    unsigned long PathsDone;
};

//Exercice 5.2
class ValueAtRisk : public StatisticsMC
{
public:
    ValueAtRisk(double alpha_);

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    std::vector<double> PathData;
    double alpha;
    unsigned long PathsDone;
};

//Exercice 5.3
class StatsGatherer : public StatisticsMC
{
public:
    StatsGatherer(const std::vector<Wrapper<StatisticsMC> >& GathererVector_);

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    std::vector<Wrapper<StatisticsMC> > GathererVector;
    unsigned long PathsDone;
};

//Exercice 6.1
class StatisticsSE : public StatisticsMC
{
public:
    StatisticsSE();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    double RunningSum;
    double RunningSum2;
    unsigned long PathsDone;
};

class StatisticsVariance : public StatisticsMC
{
public:
    StatisticsVariance();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    double RunningSum;
    double RunningSum2;
    unsigned long PathsDone;
};

class StatisticsStdDev : public StatisticsMC
{
public:
  StatisticsStdDev();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    double RunningSum;
    double RunningSum2;
    unsigned long PathsDone;
};

class StatisticsRMS : public StatisticsMC
{
public:
    StatisticsRMS();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
  double RunningSum2;
  unsigned long PathsDone;
};

class StatisticsKeepTrack : public StatisticsMC
{
public:
    StatisticsKeepTrack();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:
    double LastNumber;
    unsigned long PathsDone;
};

#endif