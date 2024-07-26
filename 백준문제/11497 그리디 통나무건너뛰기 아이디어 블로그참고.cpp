#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
// https://dkswnkk.tistory.com/232 아이디어만 참고 
int t, n , l;

int main()
{
	cin >> t;
	while(t--){
		cin >> n;
		
		priority_queue <int> pq; 		
		for(int i = 0; i < n; i++){
			cin >> l;
		    pq.push(l);
		}
		
		deque <int> dq;		
		int c = 1;
		while(!pq.empty()){
			if(c % 2 != 0){
				dq.push_front(pq.top());
			}
			else{
				dq.push_back(pq.top());
			}
			pq.pop();
			c++;
		}
		
		int result = 0;

		for(int i = 0; i < n; i++){
			int z = 0;
			if(i == n-1){
				z = abs(dq[i] - dq[0]);
			}
			else{
				z = abs(dq[i] - dq[i+1]);
			}
			result = max(result, z);
		}
		cout << result << "\n";
		
	}
}
