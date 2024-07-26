#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	bool ck = false;
	int ans_0 = 0;
	
	for(int i = 0; i < s.length(); i++){
			if(ck == false && s[i] == '0'){
				ck = true;
				ans_0++;
			}
			if(ck == true && s[i] == '1'){
				ck = false;
			}
		}
	
	ck = false;
	int ans_1 = 0;
	
	for(int i = 0; i < s.length(); i++){
			if(ck == false && s[i] == '1'){
				ck = true;
				ans_1++;
			}
			if(ck == true && s[i] == '0'){
				ck = false;
			}
		}
	cout << min(ans_0, ans_1) << endl;
}
