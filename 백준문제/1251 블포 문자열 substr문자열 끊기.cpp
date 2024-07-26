#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
string sum = "";
int main()
{
	string s;
	cin >> s;

	for(int i = 1; i < s.length()-2; i++){
		for(int j = 1; j < s.length()-i; j++){
			string temp1 = s.substr(0, i);
			string temp2 = s.substr(i,j);
			string temp3 = s.substr(i+j);
			
			reverse(temp1.begin(), temp1.end());
			reverse(temp2.begin(), temp2.end());
			reverse(temp3.begin(), temp3.end());
			
			sum = temp1 + temp2 + temp3;
			ans = min(ans, sum);
		}
	}
	cout << ans << "\n";
}
