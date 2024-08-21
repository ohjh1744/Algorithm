#include <iostream>
#include <set>
using namespace std;

int main()
{
	string s;
	cin >> s ;
	
	set<string> st;

	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		string str = "";
		for(int j = i; j<s.size(); j++){
			str = str + s[j];
			st.insert(str);
		}
		str = ""; 
	}
	cout << st.size() << endl;
	
	set<string>::iterator iter;
	for(iter = st.begin(); iter != st.end(); iter++){
		cout << *iter << " ";
	}
}
