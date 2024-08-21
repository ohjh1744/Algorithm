#include <iostream>
#include <queue>
using namespace std;

int n, l;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		pq.push(num);
	}
	
	while(!pq.empty())
	{
		if(l >= pq.top()){
			l = l + 1;
			pq.pop(); 
		}
		else{
			break;
		}
	}
	cout << l << endl;
}
