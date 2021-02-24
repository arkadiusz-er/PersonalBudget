#include "DataOfBalance.h"

void DataOfBalance::setUserId(int newUserId) {
    if (newUserId >= 0) userId = newUserId;
}

void DataOfBalance::setDate (string newDate) {
    date = newDate;
}

void DataOfBalance::setItem (string newItem) {
    item = newItem;
}

void DataOfBalance::setAmount (double newAmount) {
    amount = newAmount;
}

int DataOfBalance::getUserId() {
    return userId;
}

string DataOfBalance::getDate() {
    return date;
}

string DataOfBalance::getItem() {
    return item;
}

double DataOfBalance::getAmount() {
    return amount;
}

