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
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result; 
			permutation(result, nums, 0); 
			return result; 
		} 

		void permutation(vector<vector<int>> &result, vector<int> &nums, int pos) { 
			if(pos == nums.size()) {
				result.push_back(nums);
			}    
			for( int i = pos; i < nums.size(); ++i) {
				swap(nums[i], nums[pos]);
				permutation(result, nums, pos + 1);
				swap(nums[i], nums[pos]);
			}
		}
};

int main()
{

	vector<int> nums = {1,2,3};
	vector<vector<int>> res;
	Solution s;
	res = s.permute(nums);
	for(auto i : res) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

}
