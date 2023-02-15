#include"BancCard.h"
#include <iostream>
using std::cout;

int main()
{
    BancCard MonoBanc("Yurii Ruban", 1670336618221342, { 12, 28 }, 002, 2000);
    for (int i = 0; i < 5; i++) {
        MonoBanc.addExpense();
    }
    cout << MonoBanc.getBalanse() << endl;
    MonoBanc.listExpenses();
    cout << "\nAvailable balans: $" << MonoBanc.getBalanse() << ".";
}