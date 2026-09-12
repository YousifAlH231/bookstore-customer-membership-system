#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct book
{
    string ISBN;
    string title;
    string author;
    float price;
};

class Customer
{
protected:
    string ID;
    string name;
    string email;
    int numberOfBooks;
    book books[10];
    float totalCost;

    void calculateCost();

public:
    Customer(string = "00000");

    void set(string);
    void print();
    float getTotalCost();
};

class Member : public Customer
{
private:
    float discount;
    float netCost;

    void calculateNetCost();

public:
    Member(string = "00000", float discountRate = 1);

    void print();
};

#endif
