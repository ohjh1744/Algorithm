#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main()
{
	int n;
	cin >> n;
	int num;
	string in;
		
	for(int i =0; i < n ; i++){
		cin >> in;
		if(in == "push"){
			
			cin >> num;
			st.push(num);
		}
		else if(in == "pop"){
			
			if(st.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << st.top() << endl;
			st.pop();
		    }
		}
		else if(in == "top"){
			if(st.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << st.top() << endl;
		    }
		} 
		else if(in == "size"){
			cout << st.size() << endl;
		}
		else if(in == "empty"){
			if(st.empty() == true){
				cout << "1" << endl;
			}
			else{
			   cout << "0" << endl;
		    }
		}
	}
	
}
