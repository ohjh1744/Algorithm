#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  top: 7 ÀÛÀº°©½Ì ¿ì¼± top:¿ì¼±¼øÀ§ -> 7 > 8 > greater 


int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
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

