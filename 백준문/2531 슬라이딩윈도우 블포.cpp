#include <iostream>
#include <algorithm>
using namespace std;
int n, d, k, c;

int check[30000 + 3000 + 1];
int belt[30000 + 3000 + 1];
int cnt; // ���� ������ 
int ans;
int main()
{
	cin >> n >> d >> k >> c;
	for(int i = 0; i < n; i++){
		cin >> belt[i];
	}
	
	check[c] = 1;
	cnt = 1;
	// k����ŭ �ʹ�Ա� 
	for(int i = 0; i < k; i++){
		//����ť ó�� �迭 �ڿ� k����ŭ �߰� 
		belt[n+i] = belt[i];
		 
		if(check[belt[i]] == 0){
			cnt++;
		}
		check[belt[i]]++;
	}
	
	//�����̵� ������
	for(int i = 0; i < n; i++){
		ans = max(ans, cnt);
		check[belt[i]]--;
		if(check[belt[i]] == 0){
			cnt--;
		}
		if(check[belt[i+k]] == 0){
			cnt++;
		}
		check[belt[i+k]]++;
	}
	
	cout << ans << "\n"; 
	
	
}
