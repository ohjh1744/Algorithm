#include <iostream>
#include <stack>
using namespace std;

int ans = 0;
int main()
{
	int n;
	string inpt;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> inpt;
		stack <char> st;

		for(int i = 0; i < inpt.size(); i++){
			char cc = inpt[i];
			
			if(st.empty()){
				st.push(cc);		
			}
			else{
				if(st.top() != cc){
					st.push(cc);
				}
				else{
					st.pop();
				}
			}	
		}
		
		if(st.empty()){
			ans++;
		}
	}
	
	cout << ans << endl;
}
