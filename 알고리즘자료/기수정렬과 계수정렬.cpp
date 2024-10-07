#include <iostream>
#include <queue>
using namespace std;


//��� ���� 
int arr[1000];

// k�� ���� ����(ex 333 : 3��), n�� �迭ũ�� 
void radix_sort(int n, int k )
{
	queue <int> q[10]; // 0~9
	for(int i = 1; i <= k ; i++){
		for(int j = 1; j <= n; j++){
			int d = (arr[j] / (int)pow(10, i-1)) % 10;
			q[d].push({arr[j]});
		}
		
		int p = 1;
		for(int i = 0; i<= 9; i++){
			while(!q[i].empty()){
				arr[p] = q.front();/////////
				q.pop();
				p++;
			}
		}
	}
}

//������� 
int arr[1001];
int cnt[1000];
int s_arr[1001];
//k�� ���� ū��, n�� �迭 ũ�� 
void count_sort(int n, int k) 
{
	for(int i = 1; i <= n; i++){
		cnt[arr[i]]++;
	}
	
	for(int i = 2; i <= k; i++/){
		cnt[i] = cnt[i] + cnt[i-1];
	}
	
	for(int i = n; i >= 1; i--){
		s_arr[cnt[arr[i]]] = arr[i];
		cnt[i]--;
	}
}
