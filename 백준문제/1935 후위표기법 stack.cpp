#include <iostream>
#include <stack>
using namespace std;

int n;
string s;
int num[26];
stack <double> st;

int main()
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '*' || s[i] == '+' || s[i] == '/' || s[i] == '-'){
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			if(s[i] == '*'){
				st.push(a*b);
			}
			else if(s[i] == '+'){
				st.push(a+b);
			}
			else if(s[i] == '/'){
				st.push(a/b);
			}
			else if(s[i] == '-'){
				st.push(a-b);
			}
		}
		else{
			int d =  s[i] - 'A';
			st.push(num[d]);

		}
	}
	
	double ans = st.top();
	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";
	
}
