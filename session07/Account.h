/* Xin Song
   */

#pragma once
#include<string>
#include<iostream>
class Account{
	private:
		std::string firstname;
		std::string lastname;
		uint64_t id;
		double balance;
	public:
		Account(const std::string& firstname,const std::string& lastname, uint64_t id); //this can not be inline. ; 
		//Account::Account(const std::string& firstname,const std::string& lastname, uint64_t id){ //this can not be inline. ; 
		
		
		void deposit(double amt);
	//	~Account(){};
		friend std::ostream& operator <<(std::ostream& s, const Account& a); 

};
