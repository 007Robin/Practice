//Xin Song -- Game of life
/*
   [2nd bit, 1st bit] = [next state, current state]
	00 : dead(next) <-- dead(current) 
	01 : dead(next) <-- live(current) 
	10 : live(next) <-- dead(current) 
	11 : live(next) <-- live(current)

	L[i][j] & 1 : get current state
	L[i][j] >> 1 : get next state
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int fieldSize = 10; // the grid size is 10*10

class Life {
	public:
	int L[fieldSize + 2][fieldSize + 2];
	int generation = 0; //a number of generations to compute
	int times = 0; //how often to print the field

	Life () {
		ifstream myfile("hw3bb.dat");
		string s;
		getline(myfile, s);
		int i = 0;
		while(s[i] != ' ' && i < s.size()) {
			generation *= 10;
			generation += int(s[i] - '0');
			i++;
		}
		i += 1;
		while(s[i] != ' ' && i < s.size()) {
			times *= 10;
			times += int(s[i] - '0');
			i++;
		}
		int j = 0;
		if(!myfile.eof()) {
			while(getline(myfile, s)){
				for(int i = 0; i < fieldSize + 2; ++i) {
					if(s[i] == '*') {
						L[j][i] = 1;
					}
					if(s[i] == ' ') {
						L[j][i] = 0;
					}
				}
					j++;
			}
		}
	}

	void print() const {
		for(int i = 1; i <= fieldSize ; ++i) {
			for(int j = 1; j <= fieldSize ; ++j) {
				if(L[i][j] == 1 || L[i][j] == 3) {
					cout << "*";
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	
	// go to next state
	void get2ndstate(int L[fieldSize + 2][fieldSize + 2]) {
		for(int i = 1; i <= fieldSize; ++i) {
			for( int j = 1; j <= fieldSize; ++j) {
				L[i][j] >>= 1;
			}
		}
	}
	
	// count how many neighbors alive in current state
	int liveNeighbors(int L[fieldSize + 2][fieldSize + 2], int m, int n, int i, int j) {
		int aliveNum = 0;
		for( int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
			for(int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
				aliveNum += L[x][y] & 1;  
			}
		}
		aliveNum -= L[i][j] & 1;
		return aliveNum;
	}

	//rules to change cells whether be alive or dead
	void determieState(int L[fieldSize + 2][fieldSize + 2]) {

		for(int i = 1; i <= 10; ++i) {
			for(int j = 1; j <= 10; ++j) {
				int aliveNum = liveNeighbors(L, 12, 12, i, j);
				if(L[i][j] == 1 && aliveNum >= 2 && aliveNum <= 3) {
						L[i][j] = 3; //01 --> 11
				}
				if(L[i][j] == 0 && aliveNum == 3) {
						L[i][j] = 2;  //00 --> 10  
				}
			}
		}
	}
};

int main() {

	Life state;
	int generation = state.generation;
	int times = state.times;
	int j = 0;
	for( int i = 0; i <= generation; ++i) {		
		if( i == j)  {
			cout  << j <<"th graph"<< endl;
			state.print();
			j += times;
		}
		state.determieState(state.L);
		state.get2ndstate(state.L);
	}
}
