#include <iostream>
#include <queue> 

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int num;
			cin >> num;
			pq.push(num);
			if(pq.size() > n){
				pq.pop();
			}
		}
	}
	
	cout << pq.top() << endl; 
}
