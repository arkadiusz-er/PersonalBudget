#ifndef DATAOFBALANCE_H
#define DATAOFBALANCE_H

#include <iostream>

using namespace std;

class DataOfBalance {
protected:
    int userId;
    string date;
    string item;
    int amount;

public:
    void setUserId(int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (int newAmount);

    int getUserId();
    string getDate();
    string getItem();
    int getAmount();

};

#endif
