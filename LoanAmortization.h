#ifndef LOANAMORTIZATION_H
#define LOANAMORTIZATION_H

#include <string>
#include "AllPrograms.h"

class LoanAmortization : public AllPrograms
{
private:
	double loanAmount = 0.0;
	double interestRate = 0.0;
	double mpr = 0.0;
	double monthlyPayment = 0.0;
	double interestPayment = 0.0;
	double principalPayment = 0.0;
	int loanTerm = 0;
	std::string table;

public:
	double getLoanAmount() const;
	double getInterestRate() const;
	int getLoanTerm() const;
	void DisplayTable();
	std::string MakeTable(double _principal, double _interestRate, int _loanTerm);
};

#endif
