#ifndef DATAOFBALANCE_H
#define DATAOFBALANCE_H

#include <iostream>

using namespace std;

class DataOfBalance {
protected:
    int userId;
    string date;
    string item;
    double amount;

public:
    void setUserId(int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);

    int getUserId();
    string getDate();
    string getItem();
    double getAmount();

};

#endif
