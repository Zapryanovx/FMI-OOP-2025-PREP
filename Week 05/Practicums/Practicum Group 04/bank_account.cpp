#include <iostream>
#pragma warning(disable:4996)

namespace CONSTANTS
{
	constexpr size_t NAME_MAX_SIZE = 15;
	constexpr size_t ACCOUNT_MAX_SIZE = 30;
}

class BankAccount
{
public:

	BankAccount() = default;

	BankAccount(const char* name, const char* account, double balance = 0)
	{
		setName(name);
		setAccount(account);
		setBalance(balance);
	}

	void deposit(double ammount)
	{
		if (ammount < 0.0)
		{
			return;
		}

		balance += ammount;
	}

	void draw(double ammount)
	{
		if (ammount < 0.0)
		{
			return;
		}

		if (ammount > balance)
		{
			balance = 0.0;
			return;
		}

		balance -= ammount;
	}

	void print(std::ostream& os) const
	{
		os << "Bank Account:" << std::endl
       	   << "Name: " << name << std::endl
		   << "Account Number: " << account << std::endl
		   << "Balance: " << balance << " BGN" << std::endl;
	}

private:

	void setName(const char* name)
	{
		if (!name || strlen(name) == 0)
		{
			return;
		}
	
		strcpy(this->name, name);
	}

	void setAccount(const char* account)
	{
		if (!account || strlen(account) == 0)
		{
			return;
		}

		strcpy(this->account, account);
	}

	void setBalance(double balance)
	{
		if (balance < 0.0)
		{
			this->balance = 0.0;
			return;
		}

		this->balance = balance;
	}

	char name[CONSTANTS::NAME_MAX_SIZE + 1]{};
	char account[CONSTANTS::ACCOUNT_MAX_SIZE + 1]{};
	double balance = 0.0;
};

int main()
{

	BankAccount acc("Momo", "BG123456789", 100.0);
	acc.print(std::cout);

	acc.deposit(300);
	acc.print(std::cout);

	acc.draw(500);
	acc.draw(50);
	acc.print(std::cout);

	return 0;
}