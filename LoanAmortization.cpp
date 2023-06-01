#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "LoanAmortization.h"
using namespace std;


double LoanAmortization::getLoanAmount() const
{
	return loanAmount;
}

double LoanAmortization::getInterestRate() const
{
	return interestRate;
}

int LoanAmortization::getLoanTerm() const
{
	return loanTerm;
}

void LoanAmortization::DisplayTable()
{
	system("cls");
	cout << "Enter the loan amount: ";
	cin >> loanAmount;
	cout << "Enter the interest rate: ";
	cin >> interestRate;
	cout << "Enter the loan term in months: ";
	cin >> loanTerm;

	cout << MakeTable(loanAmount, interestRate, loanTerm);
	clearConsole();
}

string LoanAmortization::MakeTable(double _principal, double _interestRate, int _loanTerm)
{
	mpr = (_interestRate / 100) / 12;
	monthlyPayment = (_principal * mpr) / (1 - pow((1 + mpr), -_loanTerm));

	ostringstream oss;
	oss << fixed << setprecision(2);
	oss << "Month  Balance       Interest   Payment\n";
	for (int count = 0; count < _loanTerm; count++)
	{
		interestPayment = round((_principal * mpr) * 100) / 100;
		principalPayment = round((monthlyPayment - interestPayment) * 100) / 100;
		_principal -= principalPayment;

		oss << setw(5) << left << (count + 1);
		oss << setw(14) << left << _principal;
		oss << setw(12) << left << interestPayment;
		oss << setw(10) << left << principalPayment << "\n";
	}
	return oss.str();
}
