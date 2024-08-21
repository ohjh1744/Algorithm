#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int temp[n];
	int result = 0; // 0초기화 안했다고 틀렷대 ㅅㅂ 말이댐?
	 
	
	
	for(int i=0; i<n; i++){
		cin >> temp[i];
	}
	
	for(int i =0; i < n-2; i++){
		for(int j= i+1; j < n-1; j++){
			for(int z = j+1; z<n; z++){
				if(temp[i] + temp[j] + temp[z] <= m && temp[i] + temp[j] + temp[z] > result){
					result = temp[i] + temp[j] + temp[z];
					
				}
			}
		}
	}
	
	cout << result;
	
	
}
