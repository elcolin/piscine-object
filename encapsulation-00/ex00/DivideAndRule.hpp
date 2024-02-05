#ifndef DIVIDE_AND_RULE_HPP
#define DIVIDE_AND_RULE_HPP

#include <iostream>
#include <vector>
#include <limits>



class Bank
{
	private:
		class Account
		{
			private:
				int	id;
				int	value;
    		    Account(int id, int value)
				{
					this->id = id;
					this->value = value;
				}

			public:
				const int	&getId() const {
					return id;
				}
				const int	&getValue() const {
					return value;
				}
				friend class Bank;
		};
		int	liquidity;
		std::vector<Account *> clientAccounts;

	public:
        void    addValue(int id, int value);
        void    giveLoan(int id, int value);

		const int	&getLiquidity() const;
		const std::vector<Account*> &getClientsAccounts() const;

		void createAccount(int value);
		void deleteAccount(int id);
		void modifyAccount(int id, int value);

		Account &operator[](int id);

		Bank(int liquidity){
            this->liquidity = liquidity;
        }

		~Bank(){
			clientAccounts.clear();
		}
		

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
		friend std::ostream& operator << (std::ostream& p_os, const Bank::Account& p_account);


};

#endif