#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int alphabet[26]; // 0: A ~~~ 
int oddnum; //홀수 개를 가진 문자의 수
bool check[26]; // 홀수인 문자 확인 
string ans1= "";
string ans2= "";
string r_ans = "";
 
int main()
{
	cin >> s; 
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		int a = c - 'A';
		alphabet[a]++;
	}

	// 팰린드롬만들수있는지, 홀수개 알파벳이 두개이상이면 못만듬 .
	for(int i = 0; i < 26; i++){ // 팰린드롬 만들기 여부 가능확인 		
		if(alphabet[i] % 2 == 1){
			oddnum++;
		}
		if(oddnum >= 2){
			cout << "I'm Sorry Hansoo" << "\n";
			return 0;
		}
	}
	
	//1. 알바벳이 다 짝수인 경우 
	if(oddnum == 0){
		for(int i = 0; i < 26; i++){
			if(alphabet[i] > 0){
				for(int j = 0; j < alphabet[i] / 2 ; j++){
					char ch = i + 65;
					ans1 = ans1 + ch;
				}
			}
		}
		
		r_ans = ans1;
	    reverse(ans1.begin(), ans1.end());
	    ans2 = ans1;
	    r_ans = r_ans + ans2;
     	cout << r_ans << endl;
	} 
	
	//2. 홀수개의 알파벳이 있을때 
	if(oddnum == 1){
		for(int i = 0; i < 26; i++){
			if(alphabet[i] > 0){
				if(alphabet[i] % 2 == 1){
					check[i] = true; 
				} 
				for(int j = 0; j < alphabet[i] / 2 ; j++){
					char ch = i + 65;
					ans1 = ans1 + ch;
				}
			}
		}
		
		r_ans = ans1;
		for(int i = 0; i < 26; i++){
			if(check[i] == true){
				char ch = i + 65;
				r_ans = r_ans + ch;
			}
		}
		reverse(ans1.begin(), ans1.end());
	    ans2 = ans1;
	    r_ans = r_ans + ans2;
     	cout << r_ans << endl;
	} 
	return 0;
	
}
