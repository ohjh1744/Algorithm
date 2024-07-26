#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int ans;
bool b;

int main()
{
	cin >> s;
	
	for(int i = 0; i < s.length(); i++){
		b = true;
		for(int j = i; j < s.length(); j++){
			if(s[j] != s[s.length()-1-(j-i)]){
				b = false;
				break;
			}
		}
		if(b){
			ans = s.length() + i;
			cout << ans << '\n';
			return 0;
		}
	}
	
}
