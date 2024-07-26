#include <iostream>
#include <stack>
using namespace std;

stack <char> st;
string ans = "";

int main()
{
	string s;
	cin >> s;
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			ans = ans + s[i];
		}
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){  // ( 전까지 다빼서 출력하기 
				char y = st.top();
				ans = ans + y;
				st.pop();
			}
			st.pop(); // ( 없애주기 
		}
		else{ // (, *, +, - 
		    if(s[i] == '*' || s[i] == '/'){
		    	while(!st.empty() && (st.top() == '*' || st.top() == '/')){
		    		ans = ans + st.top();
		    		st.pop();
				}
			}
			else if(s[i] == '+' || s[i] == '-'){
				while(!st.empty() && st.top() != '('){
					ans = ans + st.top();
		    	    st.pop();
				} 
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty()){ // 나머지 스택에 있는거 다출력해주기 
		ans = ans + st.top();
		st.pop();
	} 
	
	cout << ans << "\n";	
}
