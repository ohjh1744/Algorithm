#include <iostream>
#include <algorithm>
using namespace std;
int n, d, k, c;

int check[30000 + 3000 + 1];
int belt[30000 + 3000 + 1];
int cnt; // 현재 종류수 
int ans;
int main()
{
	cin >> n >> d >> k >> c;
	for(int i = 0; i < n; i++){
		cin >> belt[i];
	}
	
	check[c] = 1;
	cnt = 1;
	// k개만큼 초밥먹기 
	for(int i = 0; i < k; i++){
		//원형큐 처럼 배열 뒤에 k개만큼 추가 
		belt[n+i] = belt[i];
		 
		if(check[belt[i]] == 0){
			cnt++;
		}
		check[belt[i]]++;
	}
	
	//슬라이딩 윈도우
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
