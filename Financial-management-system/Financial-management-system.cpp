#include"BancCard.h"
#include <iostream>
using std::cout;

int main()
{
    BancCard MonoBanc("Yurii Ruban", 1670336618221342, { 12, 28 }, 002, 2000);
    Expense p1({ 20, 2, 2023 }, "Ball  ", 20, 2);
    Expense p2({ 20, 2, 2023 }, "Goggles", 7, 2);
    Expense p3({ 20, 2, 2023 }, "Juse  ", 3, 1);
    Expense p4({ 20, 2, 2023 }, "Slippers", 13, 5);
    Expense p5({ 20, 2, 2023 }, "Bus ticket", 102, 4);
    Expense p6({ 20, 1, 2023 }, "Phone", 600, 5);
    Expense p7({ 20, 2, 2023 }, "Toothpaste", 8, 2);
    MonoBanc.addExpense(p1);
    MonoBanc.addExpense(p2);
    MonoBanc.addExpense(p3);
    MonoBanc.addExpense(p4);
    MonoBanc.addExpense(p5);
    MonoBanc.addExpense(p6);
    MonoBanc.addExpense(p7);
    MonoBanc.topThreeExpensesPerMonth();
    //cout << p1 << endl;
    cout << "\nAvailable card balans: $" << MonoBanc.getBalanse() << ".\n";
}