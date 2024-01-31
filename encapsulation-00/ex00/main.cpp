#include <iostream>
#include <vector>
#include <limits>
#include "DivideAndRule.hpp"


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
	// Account accountA = Account(0, 100);
	// accountA.id = 0;
	// accountA.value = 100;

	// Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;

	Bank bank = Bank(999);
	bank.createAccount(100);
	bank.createAccount(0);
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	// std::cout << "Account : " << std::endl;
	// std::cout << accountA << std::endl;
	// std::cout << accountB << std::endl;

	// std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;
	bank.giveLoan(0, 100);
	bank.addValue(0, 100);

	bank.deleteAccount(1);
	std::cout << bank << std::endl;

	bank.deleteAccount(0);

	std::cout << bank << std::endl;



	return (0);
}



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
