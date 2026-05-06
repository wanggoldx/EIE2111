//Name: Lau Wang Chun
//Student ID: 21100151D
class Account
{
public:
	int worldaccbalance;

	Account(int account_balance)
	{
		if (account_balance < 0){
			worldaccbalance = 0;
			cout << "Error : Initial balance cannot be negative.\n";
		}
		else
			worldaccbalance = account_balance;
	}

	void credit(int despoit)
	{
		worldaccbalance = worldaccbalance + despoit;
	}
	
	void debit(int withdraw)
	{
		if (withdraw > worldaccbalance )
			cout << "Debit amount exceeded account balance.\n";
		else
			worldaccbalance = worldaccbalance - withdraw;
	}

	int getBalance()	
	{
		return worldaccbalance;
	}
};



