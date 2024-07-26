#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<string> v; //입력문자열저장 
int n, m;
int h_d;
int t, a, g, c;
string input;
string ans;
int big;
 
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	for(int i = 0; i < m; i++){
		t = 0;
		a =0;
		g =0;
		c =0;
		for(int j = 0; j <n; j++){
			input = v[j];
			if(input[i] == 'T'){
				t++;
			}
			else if(input[i] == 'A'){
				a++;
			}
			else if(input[i] == 'G'){
				g++;
			}
			else if(input[i] == 'C'){
				c++;
			}
		}
		big = max(max(t, a), max(g, c));
		h_d = h_d + (n - big);
		if(big == a){
			ans = ans + 'A';
			continue;
		}
		else if(big == c){
			ans = ans + 'C';
			continue;
		}
		else if(big == g){
			ans = ans + 'G';
			continue;
		}
		else if(big == t){
			ans = ans + 'T';
			continue;
		}		
	}
	
	cout << ans << "\n";
	cout << h_d ;

}
