#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
	int n;
	cin >> n;
	int num;
	string in;
		
	for(int i =0; i < n ; i++){
		cin >> in;
		if(in == "push_front"){
			
			cin >> num;
			dq.push_front(num);
		}
		else if(in == "push_back"){
			
			cin >> num;
			dq.push_back(num);
		}
		else if(in == "pop_front"){
			
			if(dq.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << dq.front() << endl;
			dq.pop_front();
		    }
		}
		else if(in == "pop_back"){
			
			if(dq.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << dq.back() << endl;
			dq.pop_back();
		    }
		}
		else if(in == "front"){
			if(dq.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << dq.front() << endl;
		    }
		} 
		else if(in == "back"){
			if(dq.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << dq.back() << endl;
		    }
		} 
		else if(in == "size"){
			cout << dq.size() << endl;
		}
		else if(in == "empty"){
			if(dq.empty() == true){
				cout << "1" << endl;
			}
			else{
			   cout << "0" << endl;
		    }
		}
	}
	
}
