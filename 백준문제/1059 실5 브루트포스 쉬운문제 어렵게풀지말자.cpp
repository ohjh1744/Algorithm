#include <iostream>
#include <algorithm>
using namespace std;

int l, n;
int a, b;
int arr[51];
int ans; 

int main(){
	cin >> l;
	for(int i = 0; i < l; i++){
		cin >> arr[i];
	}
	cin >> n;
	
	sort(arr, arr + l);
	
	a = 0;
	b = arr[0];
	//n이 어디 구간사이에 있는지 확인
	for(int i = 0; i < l; i++){
		if(arr[i] == n){
			cout << 0;
			return 0;
		}
		else if(arr[i] > n){
			break;
		}
		else if(arr[i] < n){
			a = arr[i];
			b = arr[i+1];
		}
	}
	

	for(int i = a+1; i < b; i++){
		for(int j = i+1; j < b; j++){
			if(i <= n && n <= j){
				ans++;
			}
		}
	}
	
	
	cout << ans;
	
} 
