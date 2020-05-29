#include "Transaction.h"
#include <iostream>
#include <ctime>

Transaction::Transaction() {
	_amount = -1;
	_date = -1;
}
Transaction::Transaction(double amount, time_t date) {
	_amount = amount;
	_date = date;
}
Transaction::Transaction(const Transaction& rhs) {
	_amount = rhs._amount;
	_date = rhs._date;
}

bool Transaction :: operator<(const Transaction& rhs) const {
	if (_date < rhs._date) {
		return true;
	}
	return false;
}

bool Transaction :: operator>(const Transaction& rhs) const {
	if (_date > rhs._date) {
		return true;
	}
	return false;
}

bool Transaction :: operator<(const time_t date) const {
	if (_date < date) {
		return true;
	}
	return false;
}

bool Transaction :: operator>(const time_t date) const {
	if (_date > date) {
		return true;
	}
	return false;
}

double Transaction :: operator+(const Transaction& rhs) {
	return (_amount + rhs._amount);
}

double Transaction :: operator+(const double add) {
	return (_amount + add);
}

Transaction& Transaction :: operator=(const Transaction& rhs) {
	_amount = rhs._amount;
	_date = rhs._date;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Transaction& transaction) {
	struct tm* timeOut = localtime(&(transaction._date));
	os << transaction._amount << "\t-\t" << (timeOut->tm_hour) << ":" << timeOut->tm_min << ":" << timeOut->tm_sec << "-" << timeOut->tm_mday << "/" << (timeOut->tm_mon + 1) << "/" << (timeOut->tm_year + 1900) << "\n";
  
	return os;
} 