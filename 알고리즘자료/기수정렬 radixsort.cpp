#include <iostream>
#include <queue>
using namespace std;

// w �� ���� ����, n�� �迭���� w������ ���ڰ� n��. 
void radix_sort(int arr[], int n, int w)
{
	queue <int> q[10];
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= n; j++){
			int d = (arr[j] % (i*10)) / ((i-1)*10);
			q[d].push(arr[j]);
		}
		
		int p = 1;
		for(int i = 0; i <= 9; i++){
			while(!q[i].empty()){
				arr[p] = q[i].top();
				q.pop();
				p++; 
			}
		}
	}
	
	
}
