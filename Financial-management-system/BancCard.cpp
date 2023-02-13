#include "BancCard.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;


void Categories::selectCategory(Date date, string name, double sum)
{
	Expenses obj(date, name, sum);
	int choice;
	cout << "Please select one of the provided categories:\n";
	cout << "(press 1, 2, 3, 4, 5 to choose)\n";
	cout << "1. Groceries\n";
	cout << "2. Sport and medicine\n";
	cout << "3. Restaurants and entertainment\n";
	cout << "4. Treveling and fuel\n";
	cout << "5. Transfers and other\n";
	cin >> choice;
	switch (choice)
	{
	case 1:SportAndMedicine.push_back(obj);
		break;
	case 2:Groceries.push_back(obj);
		break;
	case 3:RestaurantAndEntertainment.push_back(obj);
		break;
	case 4:TrevelingAndFuel.push_back(obj);
		break;
	case 5:TransfersAndOther.push_back(obj);
		break;
	}
	cin.ignore();
	cin.clear();
}

void Categories::showSumForEachCategory()
{
	system("cls");
	double a = 0;
	for (auto ex : Groceries) a += ex.getCost();
	cout << "1. Groceries = " << a << endl; a = 0;
	for (auto ex : SportAndMedicine) a += ex.getCost();
	cout << "2. Sport and medicine= " << a << endl; a = 0;
	for (auto ex : RestaurantAndEntertainment) a += ex.getCost();
	cout << "3. Restaurants and entertainment= " << a << endl; a = 0;
	for (auto ex : TrevelingAndFuel) a += ex.getCost();
	cout << "4. Treveling and fuel= " << a << endl; a = 0;
	for (auto ex : TransfersAndOther) a += ex.getCost();
	cout << "5. Transfers and other= " << a << endl;
}



double BancCard::getBalanse()
{
	return balans;
}

void BancCard::addExpense()
{
	string name;
	double sum;
	int dd, mm, yyyy;
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
	categories.selectCategory(date , name, sum);
	balans -= sum;	
}

ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << "Date: " << obj.dd << "/" << obj.mm << "/" << obj.yy << "." << endl;
	return out;
}

ostream& operator<<(ostream& out, Expenses expenses)
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
