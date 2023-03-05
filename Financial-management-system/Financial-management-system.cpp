#include"BancCard.h"
#include <iostream>
#include <fstream>

using std::cout;
#pragma warning(disable : 4996)

int main()
{

    BancCard MonoBanc("Yurii Ruban", 1670336618221342, { 12, 28 }, 200, 2000);
    /*Expense p1({ 20, 2, 2023 }, "Ball", 20, 2);
    Expense p2({ 20, 2, 2023 }, "Goggles", 7, 2);
    Expense p3({ 20, 2, 2023 }, "Juse", 3, 1);
    Expense p4({ 20, 2, 2023 }, "Slippers", 13, 5);
    Expense p5({ 20, 2, 2023 }, "Bus ticket", 102, 4);
    Expense p6({ 20, 1, 2023 }, "Phone", 600, 5);
    Expense p7({ 20, 2, 2023 }, "Toothpaste", 8, 2);
    Expense p8({ 27, 2, 2023 }, "Burger", 10, 3);
    Expense p9({ 27, 2, 2023 }, "Cinema: Avatar 2", 15, 3);
    MonoBanc.addExpense(p1);
    MonoBanc.addExpense(p2);
    MonoBanc.addExpense(p3);
    MonoBanc.addExpense(p4);
    MonoBanc.addExpense(p5);
    MonoBanc.addExpense(p6);
    MonoBanc.addExpense(p7);
    MonoBanc.addExpense(p8);
    MonoBanc.addExpense(p9);
    MonoBanc.writeToFile();*/
    MonoBanc.readFromFile();
    MonoBanc.listExpenses();
    MonoBanc.listCategoriesSummery();
    cout << "Balans: $" << MonoBanc.getBalanse();
    

    
    
    /*
    vector<Expense> read;
     for (auto exp : MonoBanc.getListOfExpenses()) {
        read.push_back(exp);
    }

    std::ofstream out;
    out.open(path, std::ios::out);
    if (!out.is_open())
        cout << "File opening misstake.";
    else {
        out << read.size() << "\t";
        for (int i = 0; i < read.size(); i++) {
            out << sizeof(read[i]) << "\t";
        }
        for (int i = 0; i < read.size(); i++) {
            out.write(reinterpret_cast<char*> (&read[i]), sizeof(read[i]));
        }
        out.close();
    }
       
   std::ifstream in;
    vector<Expense> read;

    in.open(path, std::ios::in);
    if (!in.is_open())
        cout << "File opening misstake.";
    else {
        int n;
        in >> n;
        int* num = new int[n];
        for (int i = 0; i < n; i++)
        {
            in >> num[i];
        }
        for (int i = 0; i < n; i++)
        {            
            in.read(reinterpret_cast<char*> (&read[i]), num[i]);
            in.close();
        }
    }
    for (auto exp : read) {
        cout << exp << endl;
    }*/
}
