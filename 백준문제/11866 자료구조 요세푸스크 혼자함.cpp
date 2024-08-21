#include<iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	cin.tie(0); 
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
    queue <int> q;
    vector <int> v;
    
    for(int i = 0 ; i < n; i++){
    	q.push(i+1);
	}
	
	cout << "<";
	
	while(q.size()){
		for(int i = 1; i < k ; i++){
		v.push_back(q.front());
		q.pop();
		q.push(v.back());
	    }
		
		if(q.size() == 1){
			cout << q.front() << ">";
		}
		else{
		cout << q.front() << ", ";	
		}
		q.pop();
		
	}
	
	
	
}
