#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    cin.tie(0);
	cout.tie(0); 
	cin.sync_with_stdio(0);
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
				cout << "-1" << "\n";
			}
			else{
			cout << q.front() << "\n";
			q.pop();
		    }
		}
		else if(in == "front"){
			if(q.empty() == true){
				cout << "-1" << "\n";
			}
			else{
			cout << q.front() << "\n";
		    }
		} 
		else if(in == "back"){
			if(q.empty() == true){
				cout << "-1" << "\n";
			}
			else{
			cout << q.back() << "\n";
		    }
		} 
		else if(in == "size"){
			cout << q.size() << "\n";
		}
		else if(in == "empty"){
			if(q.empty() == true){
				cout << "1" << "\n";
			}
			else{
			   cout << "0" << "\n";
		    }
		}
	}
	
}
