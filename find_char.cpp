#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;
using std::vector;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); i++){
        if(s[i] == c){
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}


int main() {
    string s;
    cin >> s;
    string::size_type ctr ;
    auto index = find_char(s, 'o', ctr);
    cout << s << endl;
    cout << ctr << endl;
    cout << index << endl;
            
}
