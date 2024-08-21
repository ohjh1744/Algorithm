#include <iostream>
#include <queue>
using namespace std;

priority_queue <long long , vector<long long>, greater<long long> > pq;
int n, m;

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		long long num;
		cin >> num; 
		pq.push(num);
	}
	
	for(int i = 0; i < m; i++){
		long long first = pq.top();
		pq.pop();
		long long second =pq.top();
		pq.pop();
		long long sum = first + second;
		pq.push(sum);
		pq.push(sum);
	}
	
	long long ans = 0;
	while(!pq.empty()){
		ans = ans + pq.top();
		pq.pop();
	}
	cout << ans << "\n";
}
