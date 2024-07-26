#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	stack <char> st;
	bool flag = false;
	string s;
	getline(cin, s);
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '<'){  //괄호만나면 그전까지 쌓인 스택 출력 
			while(!st.empty()){
			   	cout << st.top();
			   	st.pop();
			}
			cout << s[i];
			flag = true;
		} 
		else if(s[i] == '>'){
			cout << s[i];    // 닫는부등호 출력하고 괄호 안열릴때로 변경 
			flag = false;
			if(i == s.size()-1){
				cout << endl;
			}
		}
		else if(!flag){ //괄호 안열릴때 
			if(s[i] == ' ' ){    // 빈칸 만나면 스택쌓인거 출력하고 띄어쓰기 
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
				cout << s[i];
			}
			else if(i == s.size()-1){ // 문자로 끝날때 
				st.push(s[i]);
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
			}
			else{
				st.push(s[i]);
			}
		}
		else if(flag){ //괄호열릴떄 
			cout << s[i];
		}
		
	}
}
