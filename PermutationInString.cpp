//Xin Song -- one of the first string's permutations is the substring of the second string.
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <map>

using namespace std;   


class Solution {
	public:
		bool checkInclusion(string s1, string s2) {
			vector<string> s2subset;
			string subset;
			subsetfun(s2subset, subset, s2, 0);
			vector<string> result;
			permutation(result, s1, 0);

			for( auto j : result) {
				cout << j << " ";
			}
			cout << endl;

			for( auto j : s2subset) {
				cout << j << " ";
			}


			for( auto anys1 : result) {
				auto iter = find(s2subset.begin(), s2subset.end(), anys1);
				if(iter != s2subset.end()) {
					return true;
				}    
			}
			return false;
		}
		void subsetfun(vector<string> &result, string &subset, string &s2, int pos){
			result.push_back(subset);
			for(int i = pos; i < s2.size(); ++i) {
				subset += s2[i];
				subsetfun(result, subset, s2, i + 1);
				subset = subset.substr(0, subset.size() - 1);  

			}
		}
		void permutation(vector<string> &result, string &s1, int pos){
			if(pos == s1.size()) {
				result.push_back(s1);
			}
			else{
				for (int i = pos; i < s1.size(); ++i) {
					swap(s1[i],s1[pos]);
					permutation(result, s1, pos + 1);
					swap(s1[i],s1[pos]);
				}    
			}
		}

};

int main()
{
	string s1 = "ab";// "hello";  //

	string s2 = "eidboaoo";//"ooolleoooleh"; //
	Solution s;

	cout << s.checkInclusion(s1, s2);    

}
