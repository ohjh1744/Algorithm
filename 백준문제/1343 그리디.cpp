#include <iostream>
using namespace std;

string a = "AAAA";
string b = "BB";

string ans = "";

int main()
{
	string s;
	cin >> s;
	
	int ct = 0;
	
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		if( c == 'X'){
			ct++;
		}
		if(c != 'X' || i == s.length() - 1){
			if(ct % 2 != 0){
			  cout << -1 ;
			  return 0;
		    }
		    int m = ct / 4;
		    for(int i = 0; i < m; i++){
		    	ans = ans + a;
			}
			ct = ct % 4;
			m = ct / 2;
			for(int i = 0; i < m; i++){
		    	ans = ans + b;
			}
			ct = 0;
			if(i == s.length()-1){
				if(c == 'X'){
					continue;
				}
			}
            ans = ans + '.' ;            
		}
		
	}
	
	cout << ans << "\n";
	
	
}
