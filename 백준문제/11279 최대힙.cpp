#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  7 8 9 10  ~ top: 10 큰값이 우선 

int main()
{
	priority_queue<int> pq;
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
				printf("%d \n", pq.top());
				pq.pop();
			}
		}
		else{
			pq.push(x);
		}
	}
	
	return 0;
}

