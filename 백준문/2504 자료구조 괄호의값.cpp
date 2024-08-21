#include <iostream>
#include <stack>
using namespace std;

int main()
{	
	stack <char> st;
 
	int answer = 0;
	int value = 1;
	
	string input;
	cin >> input;
	
	bool b = true;
	for(int i = 0; i < input.length(); i++){
		char c = input[i];
		if(c == '('){
			value = value * 2;
			st.push(c);
		}
		
		else if(c == '['){
			value = value * 3;
			st.push(c);
		}
		
		else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                b = false;
                break;
            }
            else {
                if (st.top() == '(') {
                	answer += value;
				}
                st.pop();
                value /= 2;
            }
        }
        else if(c == ']'){
            if (st.empty() || st.top() != '[') {
                b = false;
                break;
            }
            else {
                if (st.top() == '['){
                  answer += value;	
				} 
                st.pop();
                value /= 3;
            }
        }
				
	}
	
	if(b == false || !st.empty()){
		cout << "0" << endl;
	}
	else{
		cout << answer << endl;
	}
	
	
}
