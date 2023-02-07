#include "BancCard.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;

void Categories::choice(Expenses obj)
{
	int choice;
	cout << "Please select one of the provided categories:\n";
	cout << "(press 1, 2, 3, 4, 5 to choose)\n";
	cout << "1. Sport and medicine\n";
	cout << "2. Groceries\n";
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
}

void BancCard::addExpense()
{
	string name;
	int sum, choice;
	cout << "Enter name\n";
	name = cin.get();
	cin.ignore();
	cout << "Enter sum\n";
	cin >> sum;
	system("cls");
	Expenses obj(name, sum);
	categories.choice(obj);
}

int BancCard::getBalanse()
{
	return balans;
}


