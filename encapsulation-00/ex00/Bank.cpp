#include "DivideAndRule.hpp"

// Bank interactions

void Bank::addValue(int id, int value)
{
    for (std::vector<Bank::Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); it++)
    {
        if (id == (*it)->id)
        {
            if (value > 0)
            {
                liquidity += value * 5/100;
                value -= value * 5/100;
            }
            (*it)->value += value;
            return;
        }
    }
}

void    Bank::giveLoan(int id, int value)
{
    if (value > liquidity)
        return;//ajouter gestion
    for (std::vector<Bank::Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); it++)
    {
        if (id == (*it)->id)
        {
            (*it)->value += value;
            liquidity -= value;
            return;
        }
    }
}

// Account actions

void Bank::createAccount(int value)
{
	if (getClientsAccounts().size() >= static_cast<unsigned long>(std::numeric_limits<int>::max()))
	{
		//error gestion
		return;
	}
    if (!getClientsAccounts().size())
        clientAccounts.push_back(new Account(0, value));

    else
	    clientAccounts.push_back(new Account(getClientsAccounts().back()->getId() + 1, value));
}

void Bank::deleteAccount(int id)
{
    for (std::vector<Bank::Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); it++)
    {
        if (id == (*it)->id)
        {
            clientAccounts.erase(it);
            return;
        }
    }
}

void Bank::modifyAccount(int id, int value)
{
	if (clientAccounts.size() >= static_cast<unsigned long>(id))
		return;
	clientAccounts[id]->value = value;
}

// Getters

const int &Bank::getLiquidity() const
{
	return liquidity;
}

const std::vector<Bank::Account*> &Bank::getClientsAccounts() const
{
	return clientAccounts;
}