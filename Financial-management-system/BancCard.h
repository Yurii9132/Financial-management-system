#pragma once
#include<iostream>
#include<vector>
using std::string;
using std::ostream;
using std::vector;
using std::endl;

class Expenses
{
	string name;
	int cost;
public:
	Expenses(string name, int cost) : name{ name }, cost{ cost } {}
	Expenses(Expenses&& expenses) : name{ name }, cost{ cost } {}
	friend ostream& operator << (ostream& out, Expenses expenses) {
		out << expenses.name << " --\t" << expenses.cost << endl;
	}
};

struct Categories {
public:
	vector<Expenses> SportAndMedicine;
	vector<Expenses> Groceries;
	vector<Expenses> RestaurantAndEntertainment;
	vector<Expenses> TrevelingAndFuel;
	vector<Expenses> TransfersAndOther;	
	void choice(Expenses obj);
};

class ExpiryDate {
	int mm;
	int yy;
public:
	ExpiryDate(int mm, int yy) : mm{ mm }, yy{ yy } {};
	friend ostream& operator << (ostream& out, ExpiryDate expiryDate){
		out << expiryDate.mm << " / " << expiryDate.yy; return out;
	}	
};

class BancCard
{
	string nameOnCard;
	long long cardNuber;
	ExpiryDate expiryDate;
	int CVV;
	int balans;
	Categories categories;
public:
	BancCard(string nameOnCard, long long cardNumber, ExpiryDate expiryDate, int CVV, int balans = 0) :
		nameOnCard { nameOnCard },
		cardNuber { cardNuber }, 
		expiryDate { expiryDate },
		CVV { CVV }, 
		balans { balans }
	{}
	void addExpense();
	int getBalanse();
};

