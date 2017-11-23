#include<iostream>
#include "Account.h"
//#include<Bank.h>
using namespace std;
/*
#pragma once 
   */

int main() {
	Account a("a", "b", 123);
	a.deposit(100000);
	cout << a;
} 
