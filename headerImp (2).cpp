#include "header.h"

void Customer::calculateCost()
{
    totalCost = 0.0;

    for (int i = 0; i < numberOfBooks; i++)
    {
        totalCost += books[i].price;
    }
}

Customer::Customer(string numid) : ID(numid), totalCost(0)
{
    set(numid);
}

void Customer::set(string numid)
{
    ID = numid;

    ifstream customerFile("customer.txt");
    ifstream bookFile("book.txt");

    bool found = false;
    string lines;

    while (getline(customerFile, lines))
    {
        istringstream ss(lines);
        string tempID;

        ss >> tempID;

        if (tempID == numid)
        {
            found = true;

            ss.ignore();

            getline(ss, name, ',');
            getline(ss, email, ',');

            ss >> numberOfBooks;

            if (numberOfBooks > 10)
                numberOfBooks = 10;

            string bookISBNs[10];

            int count = 0;
            int bookCount = 0;

            while (getline(customerFile, lines) && count < numberOfBooks)
            {
                istringstream bookSS(lines);
                bookSS >> bookISBNs[count++];
            }

            while (getline(bookFile, lines) && bookCount < numberOfBooks)
            {
                istringstream bookSS(lines);

                book b;

                bookSS >> b.ISBN;
                bookSS.ignore();

                getline(bookSS, b.title, '\t');
                getline(bookSS, b.author, '\t');

                bookSS >> b.price;

                for (int i = 0; i < count; i++)
                {
                    if (b.ISBN == bookISBNs[i])
                    {
                        books[bookCount++] = b;
                        break;
                    }
                }
            }

            break;
        }
    }

    customerFile.close();
    bookFile.close();

    calculateCost();
}

void Customer::print()
{
    cout << ID << " " << name << " " << email << endl;

    cout << "Bought the following "
         << numberOfBooks
         << " books" << endl;

    cout << endl;

    for (int i = 0; i < numberOfBooks; i++)
    {
        cout << " "
             << books[i].ISBN << " "
             << books[i].title << " "
             << books[i].author << " "
             << books[i].price
             << " dirhams"
             << endl;
    }

    cout << endl;

    cout << "The cost of the above books is "
         << totalCost
         << " dirhams"
         << endl;

    cout << endl;

    cout << "=========================================================="
         << endl;

    cout << endl;
}

float Customer::getTotalCost()
{
    return totalCost;
}

Member::Member(string id, float discountRate)
    : Customer(id), discount(discountRate), netCost(0.0)
{
    calculateNetCost();
}

void Member::calculateNetCost()
{
    netCost = getTotalCost() * (1.0 - discount / 100);
}

void Member::print()
{
    Customer::print();

    cout << "This customer is a member and has a "
         << discount
         << "% discount"
         << endl;

    cout << "The net cost of this member is "
         << netCost
         << " dirhams"
         << endl;
}