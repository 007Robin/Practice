#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

//like STL find() using template
template<typename iterator, typename value>
iterator findvalue(iterator beg, iterator end, const value& v){
	cout << v << endl;
	for(; beg != end && *beg != v; ++beg){
	}
	return beg;
}

int main(){
	vector<int> v = {9,6,3,1,7};
	vector<int>::iterator a = findvalue(v.begin(), v.end(), 9);
	cout << *a<< endl;
	
	list<string> l = {"a", "abc", "poi"};
	list<string>::iterator b = findvalue(l.begin(), l.end(),"abc");
	cout << *b << endl;
}
