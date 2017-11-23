#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Life {
	public:
		int L[12][12];
		Life() { 

			ifstream fin("lifestart.dat"); 
			int j = 0;
/*
	while( fin.getline(str,LINE_LENGTH) )
	{   
		cout  << j << endl;
		for(int i = 0; i < 12; ++i) {
			L[j][i] = str[i] - '0';
		}
		j++;
	}
*/

			string s;
			if(!fin.eof()){
				while(getline(fin, s)){
					for(int i = 0; i < 12; ++i) {
						L[j][i] = s[i] - '0';
					}
					j++;
				}
			}		
		}


		void print() const {
			for(int i = 0; i <12; ++i) {
				for(int j = 0; j < 12; ++j) { 
					cout << L[i][j];
				}
				cout << endl;
			}
		}
};

int main() {
	/*ifstream fin("lifestart.dat"); 
//	const int LINE_LENGTH = 10; 
//	char str[LINE_LENGTH];  
	int L[12][12] = {0};
	int j = 0;
/*
	while( fin.getline(str,LINE_LENGTH) )
	{   
		cout  << j << endl;
		for(int i = 0; i < 12; ++i) {
			L[j][i] = str[i] - '0';
		}
		j++;
	}
*/

/*	string s;
	if(!fin.eof()){
		while(getline(fin, s)){
			for(int i = 0; i < 12; ++i) {
				L[j][i] = s[i] - '0';
			}
			j++;
		}
	}

	for(int i = 0; i <12; ++i) {
		for(int j = 0; j < 12; ++j) { 
			cout << L[i][j];
		}
		cout << endl;
	}
	*/

	Life state;
	state.print();
}

