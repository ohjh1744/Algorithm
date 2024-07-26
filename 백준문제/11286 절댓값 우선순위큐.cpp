#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 10 9 8 7 ~ top: 7


int main()
{
  
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int num;
	scanf("%d", &num);
	for(int i=0; i< num; i++){
		int x;
		scanf("%d", &x);
		if(x == 0){
			if(pq.empty()){
				printf("0\n");
			}
			else{
				printf("%d \n", pq.top().second);
				pq.pop();
			}
		}
		else{
			 	pq.push(make_pair(abs(x), x)); // 

		}
	}
	
	return 0;
}
