#include<iostream>
#include<string>

using namespace std;

int main(int argv, char** argc) {
	if(strcmp(argc[1], "-d") == 0) {
		cout << argc[2] << endl;
	}
	else {
		string str1 = argc[1];
		string str2 = argc[2];
		int l1 = str1.size();
		int l2 = str2.size();
		cout << l1 << l2 << endl;
		cout << "str1: " << str1 << endl;
		if( l1 <= l2 ) {
			for(auto i = 0; i < l1; ++i) {
				str1[i] = str2[i];
			}
		}
		else {
			for(auto i = 0; i < l2; ++i) {
				str1[i] = str2[i];
			}
			for(auto j = l2; j < l1; ++j) {
				str1[j] = str2[l2 - 1];
			}
		}	
		cout << "new_str1:" << str1 << endl;
		char word;
		while(cin >> word)
		{
			if(str1.find(word))
				cout << 
		}
	}
}
