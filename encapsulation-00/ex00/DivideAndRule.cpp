#include <iostream>
#include <vector>
#include <limits>

// struct Account
// {
// 	int id;
// 	int value;


// 	Account() :
// 		id(-1),
// 		value(0)
// 	{
	
// 	}

// 	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
// 	{
// 		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
// 		return (p_os);
// 	}
// };

// struct Bank
// {
// 	int liquidity;
// 	std::vector<Account *> clientAccounts;

// 	Bank() :
// 		liquidity(0)
// 	{

// 	}

// 	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
// 	{
// 		p_os << "Bank informations : " << std::endl;
// 		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
// 		for (auto &clientAccount : p_bank.clientAccounts)
//         p_os << *clientAccount << std::endl;
// 		return (p_os);
// 	}
// };

class Account
{
	private:
		int	id;
		int	value;
	public:
		const int	&getId() const {
			return id;
		}
		const int	&getValue() const {
			return value;
		}

		Account(int id, int value)
		{
			this->id = id;
			this->value = value;
		}

		Account()
		{
			this->id = -1;
			this->value = 0;
		}
		friend class Bank;

};

class Bank
{
	private:
		int	liquidity;
		std::vector<Account *> clientAccounts;

	public:
		const int	&getLiquidity() const;
		const std::vector<Account*> &getClientsAccounts() const;
		void createAccount(int value);
		void createAccount(Account &account);
		void deleteAccount(int id);
		void modifyAccount(int id, int value);

		Bank(int liquidity);
		Bank();
		// ~Bank();

};


void Bank::createAccount(int value)
{
	if (getClientsAccounts().size() >= std::numeric_limits<int>::max())
	{
		return;
	}
	clientAccounts.push_back(new Account(getClientsAccounts().back()->getId() + 1, value));
}

void Bank::createAccount(Account &account)
{
	if (getClientsAccounts().size() >= std::numeric_limits<int>::max())
	{
		//error gestion
		return;
	}
	account.id = getClientsAccounts().back()->getId() + 1;
	clientAccounts.push_back(&account);
}

void Bank::modifyAccount(int id, int value)
{
	if (clientAccounts.size() >= static_cast<unsigned long>(id))
		return;
	clientAccounts[id]->value = value;
}

const int &Bank::getLiquidity() const
{
	return liquidity;
}

const std::vector<Account*> &Bank::getClientsAccounts() const
{
	return clientAccounts;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
	std::vector<Account*> accounts = p_bank.getClientsAccounts();
	for (std::vector<Account*>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
    	p_os << *(*it) << std::endl;
	}

	return (p_os);
}

int main()
{
	Account accountA = Account(0, 100);
	// accountA.id = 0;
	// accountA.value = 100;

	Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;

	Bank bank = Bank();
	bank.createAccount(accountA);
	bank.createAccount(accountB);
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
