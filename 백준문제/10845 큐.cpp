#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

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
			q.push(num);
		}
		else if(in == "pop"){
			
			if(q.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << q.front() << endl;
			q.pop();
		    }
		}
		else if(in == "front"){
			if(q.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << q.front() << endl;
		    }
		} 
		else if(in == "back"){
			if(q.empty() == true){
				cout << "-1" << endl;
			}
			else{
			cout << q.back() << endl;
		    }
		} 
		else if(in == "size"){
			cout << q.size() << endl;
		}
		else if(in == "empty"){
			if(q.empty() == true){
				cout << "1" << endl;
			}
			else{
			   cout << "0" << endl;
		    }
		}
	}
	
}
