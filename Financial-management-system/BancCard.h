#pragma once
#include<iostream>
#include<vector>
using std::string;
using std::ostream;
using std::vector;
using std::endl;

struct Expences
{
	string name;
	int cost;
	Expences(string name, int cost) : name{ name }, cost{ cost } {}
	friend ostream& operator << (ostream& out, Expences expences) {
		out << expences.name << " --\t" << expences.cost << endl;
	}
};

class Categories {
	vector<Expences> SportAndMedicine;
	vector<Expences> Groceries;
	vector<Expences> RestaurantAndEntertainment;
	vector<Expences> TrevelingAndFuel;
	vector<Expences> other;
};

struct ExpiryDate {
	int mm;
	int yy;
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
public:
	BancCard(string nameOnCard, long long cardNumber, ExpiryDate expiryDate, int CVV, int balans = 0) :
		nameOnCard { nameOnCard },
		cardNuber { cardNuber }, 
		expiryDate { expiryDate },
		CVV { CVV }, 
		balans { balans }
	{}
	int getBalanse();
};

