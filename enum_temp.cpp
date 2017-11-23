#include<iostream>
using namespace std;
enum class SEX{
	MALE,
	FEMALE,
	NUM_OF_SEX
};
int main()
{
	cout << "value of MALE is: " << (int)SEX::MALE << endl;
	cout << "value of FEMALE is: " << (int)SEX::FEMALE << endl;
	cout << "There are totally " << (int)SEX::NUM_OF_SEX << "sexs in world" << endl;
}

