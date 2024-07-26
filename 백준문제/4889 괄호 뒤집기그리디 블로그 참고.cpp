#include <iostream>
#include <stack>
using namespace std;

//https://imnotabear.tistory.com/259
string s;
int ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	while(1){
		cin >> s;
		if(s[0] == '-'){
			return 0;
		}
		
		stack <char> st;
		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			// !st.empty()는 런타임에러 막기위해 비어있는데 st.pop()은 이론상 안되므로 실행은되지만 
			if(c == '}' && !st.empty() && st.top() == '{'){
				st.pop();
			}
			else{
				st.push(c);
			}

		}

		while(!st.empty()){
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();
			if(c1 == c2){
				ans++;
			}
			else{
				ans = ans + 2;
			}
		}
		
		cout << t << ". " << ans << "\n";
		t++;		
		ans = 0;
		
	}
	
	
	
}
