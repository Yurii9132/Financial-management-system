#pragma once
#include<iostream>
#include<vector>
using std::string;
using std::ostream;
using std::vector;
using std::endl;

class Date {
	int dd;
	int mm;
	int yy;
public:
	Date() : Date(0, 0, 0){}
	Date(int dd, int mm, int yy) : dd{ dd }, mm{ mm }, yy{ yy } {}
	friend ostream& operator << (std::ostream& out, const Date& obj);
	bool operator == (const Date& obj);
	void operator = (const Date& obj);
	bool operator < (const Date& obj);
	int getDay();
	int getMonth();
	int getYear();
};

enum Categories { 
	Groceries = 1, Sport_and_medicine, Restaurants_and_entertainment,
	Treveling_and_fuel, Clothes_and_other
};


class Expense
{
	Date date;
	string name;
	double cost;
	int categorie;
public:
	Expense() : Expense({0, 0, 0}, "", 0, 0) {}
	Expense(Date date, string name, double cost, int catogorie) : date{ date }, name{ name }, cost{ cost }, categorie{ catogorie} {}
	friend ostream& operator << (ostream& out, Expense expenses);
	void operator = (const Expense& obj);
	double getCost() { return cost; }
	Date getDate() { return date; }
	string getName() { return name; }
	int getCategorie() { return categorie; }

};

class ExpiryDate {
	int mm;
	int yy;
public:
	ExpiryDate() : ExpiryDate(0, 0){}
	ExpiryDate(int mm, int yy) : mm{ mm }, yy{ yy } {};
	friend ostream& operator << (ostream& out, ExpiryDate expiryDate);
};

class BancCard
{
	const static char path[50];
	string nameOnCard;
	const long long cardNuber;
	ExpiryDate expiryDate;
	const int CVV;
	double balans;	
	vector<Expense> expenses;
public:
	BancCard() : cardNuber{ 0 },
		CVV{ 0 }
	{}
	
	BancCard(string nameOnCard, long long cardNumber, ExpiryDate expiryDate, int CVV, double balans = 0.0) :
		nameOnCard { nameOnCard },
		cardNuber { cardNuber }, 
		expiryDate { expiryDate },
		CVV { CVV }, 
		balans { balans }		
	{}
	BancCard(BancCard& sors) :
		nameOnCard{ sors.nameOnCard },
		cardNuber{ sors.cardNuber },
		expiryDate{ sors.expiryDate },
		CVV{ sors.CVV },
		balans{ sors.balans }
	{
		for (auto exp : sors.expenses) {
			this->expenses.push_back(exp);
		}
	}
	double getBalanse();
	void addExpense();
	void addExpense(Expense obj);
	void addExpense(Date date, string name, double cost, int categorie);
	void listCategoriesSummery();
	void listExpenses();
	void topThreeExpensesPerWeek();
	void topThreeExpensesPerMonth();
	void pushList(vector<Expense> readFromFile);
	vector<Expense> getListOfExpenses();
	void writeToFile();
	void readFromFile();
};

