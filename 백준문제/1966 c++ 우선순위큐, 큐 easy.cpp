#include <iostream>
#include <queue> 
using namespace std;

int t, n, m;
int ct = 0; // 몇번쨰 인쇄 
int main()
{
	cin >> t;
	for(int i = 0; i < t; i++){
		ct = 0;
		cin >> n >> m;
		queue <pair < int, int > > q; // 중요도, 순서 
		priority_queue <int> pq; 
		for(int j = 0; j < n; j++){
			int num;
			cin >> num;
			q.push({num , j});
			pq.push(num); 
		}
		while(!q.empty()){
			int pq_p = pq.top();
			int q_pf = q.front().first;
			int q_ps = q.front().second;
			
			if(q_pf != pq_p){
				q.pop();
				q.push({q_pf,q_ps});
			}
			else{
				ct++;
				if(q_ps == m){
					cout << ct << "\n";
					break;
				}
				pq.pop();
				q.pop();
			}
		}
	}
	
	
	
}
