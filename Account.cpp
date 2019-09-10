#include "Account.h"

const double PENALTY_FEE = -20;

Account::Account()
{
	amount = 0.0;
}

Account::Account(double a)
{
	amount = a;
}

void Account::deposit(double a)
{
	amount += a;
}

void Account::withdraw(double a)
{
	if(a > amount)
		amount += PENALTY_FEE;
	else
		amount -= a;

}

double Account::get_balance()
{
	return amount;
}
