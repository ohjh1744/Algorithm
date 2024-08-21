#include <iostream>
#include <stack>
using namespace std;

int t;
stack <char> st;
bool check = true;

int main()
{
	cin >> t;
	string input;
	for(int i = 0; i < t; i++){
		cin >> input;
		for(int i = 0; i < input.length(); i++){
			if(input[i] == '('){
				st.push(input[i]);
			}
			else if(input[i] == ')'){
				if(st.empty()){
					check = false;
					break;
				}
				else{
					st.pop();
				} 
			}
		}
		if(check == true && st.empty()){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		check = true;
		while(!st.empty()){
			st.pop();
		} 
	}
	
	
}
