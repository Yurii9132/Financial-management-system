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
	Date(int dd, int mm, int yy) : dd{ dd }, mm{ mm }, yy{ yy } {}
	friend ostream& operator << (std::ostream& out, const Date& obj);
	bool operator == (const Date& obj);
	void operator = (const Date& obj);
	bool operator < (const Date& obj);
	int getDay();
	int getMonth();
};

enum Categories { 
	Groceries = 1, Sport_and_medicine, Restaurants_and_entertainment,
	Treveling_and_fuel, Transfers_and_other
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
	void operator = (Expense obj);
	double getCost() { return cost; }
	Date getDate() { return date; }
	string getName() { return name; }
	double getCategorie() { return categorie; }
};

class ExpiryDate {
	int mm;
	int yy;
public:
	ExpiryDate(int mm, int yy) : mm{ mm }, yy{ yy } {};
	friend ostream& operator << (ostream& out, ExpiryDate expiryDate);
};

class BancCard
{
	string nameOnCard;
	const long long cardNuber;
	ExpiryDate expiryDate;
	const int CVV;
	double balans;	
	vector<Expense> expenses;
public:
	BancCard(string nameOnCard, long long cardNumber, ExpiryDate expiryDate, int CVV, double balans = 0.0) :
		nameOnCard { nameOnCard },
		cardNuber { cardNuber }, 
		expiryDate { expiryDate },
		CVV { CVV }, 
		balans { balans }		
	{}
	double getBalanse();
	void addExpense();
	void listExpenses();
	void topThreeExpensesPerWeek();
	void topThreeExpensesPerMonth();
};

