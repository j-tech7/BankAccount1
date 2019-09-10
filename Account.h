#ifndef Account_h
#define Account_h

using namespace std;

class Account
{
	public:
		Account();
		Account(double amount);
		void deposit(double a);
		void withdraw(double a);
		double get_balance();
	private: 
		double amount;
	
};

#endif
