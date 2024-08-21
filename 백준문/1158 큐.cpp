#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	int ct = 1;
	cout << "<";
	while(!q.empty()){
		if(ct == k){
			if(q.size() == 1){
				cout << q.front() << ">";
				q.pop();
			}
			else{
			    cout << q.front() << ", ";
			    q.pop();
			    ct = 1;	
			}
			
		}
		else{
			q.push(q.front());
		    q.pop();
		    ct++;
		}
	}
	
}
