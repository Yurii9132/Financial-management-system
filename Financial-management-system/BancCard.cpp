#include "BancCard.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>

using std::cout;
using std::cin;
using std::string;

const char BancCard::path[50] = "Accaunt.txt";

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
	cout << "5. Clothes and other\n";
	cin >> categorie;
	Expense obj(date, name, sum, categorie);
	expenses.push_back(obj);
	balans -= sum;	
	system("cls");
}

void BancCard::addExpense(Expense obj)
{
	expenses.push_back(obj);
	balans -= obj.getCost();
}

void BancCard::addExpense(Date date, string name, double cost, int categorie)
{
	Expense obj(date, name, cost, categorie);
	expenses.push_back(obj);
	balans -= cost;
}

void BancCard::listCategoriesSummery()
{
	int n;
	double groceries = 0,
		   sport_and_medicine = 0,
		   restaurants_and_entertainment = 0,
		   treveling_and_fuel = 0,
		   clothes_and_other = 0;
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
		case Categories::Clothes_and_other: clothes_and_other += cat.getCost();
			break;
		}		
	}
	cout << "1. Groceries: " << groceries << endl;
	cout << "2. Sport and medicine: " << sport_and_medicine << endl;
	cout << "3. Restaurants and entertainment: " << restaurants_and_entertainment << endl;
	cout << "4. Treveling and fuel: " << treveling_and_fuel << endl;
	cout << "5. Clothes and other: " << clothes_and_other << endl;
}

void BancCard::listExpenses()
{
	for (auto exp : expenses) {
		cout << exp << endl;
	}
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
	/*for_each(monthExpenses.begin(), monthExpenses.end(), [](Expense& obj) {
		cout << obj;
		});*/
	sort(monthExpenses.begin(), monthExpenses.end(), [](Expense& obj, Expense& objNext) {
		if (obj.getCost() < objNext.getCost()) return true;
		else return false;
		});

	int n = 1;
	/*for (auto it = monthExpenses.begin(); it != monthExpenses.end() && it < (monthExpenses.begin() + 3); it++)
	{
		cout << n++ << ". " << *it;
		;
	}*/
	for (int i = 0; i < 3 && i < monthExpenses.size(); i++)
	{
		cout << i + 1 << ". " << monthExpenses[i] << endl;
	}
	if (!monthExpenses.size())
	{
		cout << "No spending found in the selected month\n";
	}
}

void BancCard::pushList(vector<Expense> readFromFile)
{
	this->expenses.clear();
	for (auto exp : readFromFile) {
		this->expenses.push_back(exp);
	}
}

vector<Expense> BancCard::getListOfExpenses()
{
	return expenses;
}

void BancCard::writeToFile()
{
	std::ofstream out;
	out.open(path, std::ios::out);
	if (!out.is_open())
		cout << "File opening misstake.";
	else {
		out << balans << endl;
		for (int i = 0; i < expenses.size(); i++) {
			out << expenses[i].getDate().getDay() << "\t";
			out << expenses[i].getDate().getMonth() << "\t";
			out << expenses[i].getDate().getYear() << "\t";
			out << expenses[i].getCost() << "\t";
			out << expenses[i].getCategorie() << "\t";
			out << expenses[i].getName() << "\t";
			if (i < expenses.size() - 1) out << endl;
		}
		out << balans;
	}
}

void BancCard::readFromFile()
{
	std::ifstream in;
	int read_dd, read_mm, read_yy, read_categorie;
	double read_cost;
	string read_name;
	Date date;
	Expense read;
	in.open(path, std::ios::in);
	if (!in.is_open())
		cout << "File opening misstake.";
	else {
		in >> this->balans;
		while (!in.eof())
		{
			in >> read_dd;
			in >> read_mm;
			in >> read_yy;
			in >> read_cost;
			in >> read_categorie;
			getline(in, read_name);
			expenses.push_back(Expense({ read_dd, read_mm, read_yy }, read_name, read_cost, read_categorie));
		}
	}
}


ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << obj.dd << "/" << obj.mm << "/" << obj.yy;
	return out;
}

ostream& operator<<(ostream& out, Expense expenses)
{
	out << expenses.date << ":\t";
	out << "$" << expenses.cost << "\t";
	out << expenses.name << "   \t";
	switch (expenses.categorie)
	{
	case Categories::Groceries: out << " Groceries.";
		break;
	case Categories::Sport_and_medicine: out << " Sport and medicine.";
		break;
	case Categories::Restaurants_and_entertainment: out << " Restaurants and entertainment.";
		break;
	case Categories::Treveling_and_fuel: out << " Treveling and fuel.";
		break;
	case Categories::Clothes_and_other: out << " Clothes and other.";
		break;
	}
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

int Date::getYear()
{
	return yy;
}

void Expense::operator=(const Expense& obj)
{
	this->date = obj.date;
	this->name = obj.name;
	this->cost = obj.cost;
	this->categorie = obj.categorie;
}
