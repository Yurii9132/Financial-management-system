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
	Date() {}
	Date(int dd, int mm, int yy) : dd{ dd }, mm{ mm }, yy{ yy } {}
	friend ostream& operator << (std::ostream& out, const Date& obj);
	bool operator == (const Date& obj);
	void operator = (const Date& obj);
	bool operator < (const Date& obj);
	int getDay();
	int getMonth();
};

class Expenses
{
	Date date;
	string name;
	double cost;
public:
	Expenses() : Expenses({0, 0, 0}, "", 0) {}
	Expenses(Date date, string name, double cost) : date{ date }, name { name }, cost{ cost } {}
	friend ostream& operator << (ostream& out, Expenses expenses);
	double getCost() { return cost; }
};

struct Categories {
protected:
	vector<Expenses> SportAndMedicine;
	vector<Expenses> Groceries;
	vector<Expenses> RestaurantAndEntertainment;
	vector<Expenses> TrevelingAndFuel;
	vector<Expenses> TransfersAndOther;	
public:
	void selectCategory(Date date, string name, double sum);
	void showSumForEachCategory();
	void topThreeExpensesPerWeek();
	void topThreeExpensesPerMonth();
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
	long long cardNuber;
	ExpiryDate expiryDate;
	int CVV;
	double balans;
	Categories categories;
	Expenses expenses;
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
	void listExpenses() {
		categories.showSumForEachCategory();
	}
};

