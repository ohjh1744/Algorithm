#include<iostream>
using namespace std;

int n;
bool check[1000];
int ans;

int main()
{
	for(int i = 100; i <= 999; i++){ //중복된숫자 빼기 
		check[i] = true;
		string s = to_string(i);
	    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]){
	    	check[i] = false;
		}
		if(s[0] == '0' || s[1] == '0'|| s[2] == '0'){
			check[i] = false;
		} 
	}
	
	
	cin >> n;
	for(int i = 0; i < n; i++){
		string num; 
		int strike , ball;
		cin >> num >> strike >> ball;
		for(int j = 100; j <= 999; j++){
			string s = to_string(j);
			int s_strike = 0, s_ball = 0;
			if(check[j] == false){
				continue;
			}
			for(int z = 0; z < 3; z++){
				for(int k = 0; k < 3; k++){
					if(z == k && num[z] == s[k]){
						s_strike++;
					}
					if(z != k && num[z] == s[k]){
						s_ball++;
					}
				}
			}
			if(strike != s_strike || ball != s_ball){
				check[j] = false;
			}
		} 
	}
	
	for(int i = 100; i <= 999; i++){ 
		if(check[i] == true){
			ans++;
		}
	}
    cout << ans ;
	
}
