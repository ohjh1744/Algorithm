#include <iostream>
using namespace std;

int n, k;
int temp[1000001];
int ans = 99999999;

//1번째 투포인터 공식 버전 
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	int st = 0;
	int end = 0;
	int sum = 0; // 집합크기 
	int ct = 0; // k개수만족 
	
	
	while(end <= n){
		if(ct == k){
			if(sum < ans){
				ans = sum;
			}
			sum--;
			st++;
			if(temp[st] == 1){
				ct--;
			}
			
		}
		else if(ct < k){
			sum++;
			end++;
			if(temp[end] == 1){
				ct++;
			}
			
		}
	}
	
	if(ans == 99999999){
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	
}

//2번째 내가 이해하고 짠 투포인터
#include <iostream>
using namespace std;

int n, k;
int temp[1000001];
int ans = 99999999;

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	int st = 0;
	int end = 0;
	int sum = 0; // 집합크기 
	int ct = 0; // k개수만족 
	
	
	while(end <= n){
		if(ct == k){
			if(sum < ans){
				ans = sum;
			}
			st++;
			if(temp[st] == 1){
				ct--;
			}
			sum--;
		}
		else if(ct < k){
			end++;
			if(temp[end] == 1){
				ct++;
			}
			sum++;
		}
	}
	
	if(ans == 99999999){
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	
}   
