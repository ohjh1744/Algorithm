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
		if(s[i] == '<'){  //��ȣ������ �������� ���� ���� ��� 
			while(!st.empty()){
			   	cout << st.top();
			   	st.pop();
			}
			cout << s[i];
			flag = true;
		} 
		else if(s[i] == '>'){
			cout << s[i];    // �ݴºε�ȣ ����ϰ� ��ȣ �ȿ������� ���� 
			flag = false;
			if(i == s.size()-1){
				cout << endl;
			}
		}
		else if(!flag){ //��ȣ �ȿ����� 
			if(s[i] == ' ' ){    // ��ĭ ������ ���ý��ΰ� ����ϰ� ���� 
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
				cout << s[i];
			}
			else if(i == s.size()-1){ // ���ڷ� ������ 
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
		else if(flag){ //��ȣ������ 
			cout << s[i];
		}
		
	}
}
