#include "BancCard.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using std::cout;
using std::cin;
using std::string;


double BancCard::getBalanse()
{
	return balans;
}

void BancCard::addExpense()
{
	string name;
	double sum;
	int dd, mm, yyyy, categorie;
	cout << "Enter date(dd mm yyyy):\n";
	cin >> dd >> mm >> yyyy;
	Date date(dd, mm, yyyy);
	cin.clear();
	cin.ignore();
	cout << "Enter name\n";
	getline(cin, name);
	cout << "Enter sum\n";
	cin >> sum;
	system("cls");
	cout << "Please select one of the provided categories:\n";
	cout << "(press 1, 2, 3, 4, 5 to choose)\n";
	cout << "1. Groceries\n";
	cout << "2. Sport and medicine\n";
	cout << "3. Restaurants and entertainment\n";
	cout << "4. Treveling and fuel\n";
	cout << "5. Transfers and other\n";
	cin >> categorie;
	Expense obj(date, name, sum, categorie);
	expenses.push_back(obj);
	balans -= sum;	
	system("cls");
}

void BancCard::listExpenses()
{
	int n;
	double groceries = 0,
		   sport_and_medicine = 0,
		   restaurants_and_entertainment = 0,
		   treveling_and_fuel = 0,
		   transfers_and_other = 0;
	for (auto cat : expenses) {
		n = cat.getCategorie();
		switch (n)
		{
		case Categories::Groceries: groceries += cat.getCost();
			break;
		case Categories::Sport_and_medicine: sport_and_medicine += cat.getCost();
			break;
		case Categories::Restaurants_and_entertainment: restaurants_and_entertainment += cat.getCost();
			break;
		case Categories::Treveling_and_fuel: treveling_and_fuel += cat.getCost();
			break;
		case Categories::Transfers_and_other: transfers_and_other += cat.getCost();
			break;
		}		
	}
	cout << "1. Groceries: " << groceries << endl;
	cout << "2. Sport and medicine: " << sport_and_medicine << endl;
	cout << "3. Restaurants and entertainment: " << restaurants_and_entertainment << endl;
	cout << "4. Treveling and fuel: " << treveling_and_fuel << endl;
	cout << "5. Transfers and other: " << transfers_and_other << endl;
}

void BancCard::topThreeExpensesPerWeek()
{
}

void BancCard::topThreeExpensesPerMonth()
{
	int mm;
	cout << "Enter number of the month\n";
	cin >> mm;
	vector<Expense> monthExpenses;
	for (auto exp : expenses) {
		if (exp.getDate().getMonth() == mm)
		{
			monthExpenses.push_back(exp);
		}
	}
	sort(monthExpenses.begin(), monthExpenses.end(),
		[](Expense& obj, Expense& objNext)
		{
				if (obj.getCost() < objNext.getCost()) return true;				
		});
	int n;
	for (int i = 0; i < 3; i++)
	{
		n = monthExpenses[i].getCategorie();
		switch (n)
		{
		case Categories::Groceries: cout << "Categorie groceries\n";
			break;
		case Categories::Sport_and_medicine: cout << "Categorie sport and medicine\n";
			break;
		case Categories::Restaurants_and_entertainment: cout << "Categorie restaurants and entertainment\n";
			break;
		case Categories::Treveling_and_fuel: cout << "Categorie treveling and fuel\n";
			break;
		case Categories::Transfers_and_other: cout << "Categorie transfers and other\n";
			break;
		}
		cout << "Expense's date" << monthExpenses[i].getDate() << endl;
		cout << "Expense's name: " << monthExpenses[i].getName() << endl;
		cout << "Sum $" << monthExpenses[i].getCost() << endl;
	}
}


ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << "Date: " << obj.dd << "/" << obj.mm << "/" << obj.yy << "." << endl;
	return out;
}

ostream& operator<<(ostream& out, Expense expenses)
{
	out << expenses.date << ":\t" << expenses.name << " --\t" << expenses.cost << endl;
	return out;
}



ostream& operator<<(ostream& out, ExpiryDate expiryDate)
{
	out << expiryDate.mm << " / " << expiryDate.yy; return out;
}

bool Date::operator==(const Date& obj)
{
	bool res = this->dd == obj.dd && this->mm == obj.mm && this->yy == obj.yy;
	return res;
}

void Date::operator=(const Date& obj)
{
	this->dd = obj.dd;
	this->mm = obj.mm;
	this->yy = obj.yy;
}

bool Date::operator<(const Date& obj)
{
	if (this->yy < obj.yy)  return true;
	else if (this->yy > obj.yy) return false;
	else {
		if (this->mm < obj.mm) return true;
		else if (this->mm > obj.mm) return false;
		else {
			if (this->dd < obj.dd) return true;
			else  return false;
		}
	}
}

int Date::getDay()
{
	return dd;
}

int Date::getMonth()
{
	return mm;
}

void Expense::operator=(Expense obj)
{
	this->date = obj.date;
	this->name = obj.name;
	this->cost = obj.cost;
}
