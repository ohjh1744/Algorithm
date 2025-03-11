#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

string s;
set<string > st;

int main(){
   
   cin >> s;
   
   for(int i = 0; i < s.length(); i++){
   	st.insert(s.substr(i, i+ s.length()));
   }
   
   set<string> :: iterator it;
   for(it = st.begin(); it != st.end(); it++){
   	  cout << *it << "\n";
   }
}
