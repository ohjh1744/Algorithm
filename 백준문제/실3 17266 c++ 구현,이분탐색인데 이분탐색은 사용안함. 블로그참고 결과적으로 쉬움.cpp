#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

int n, m;
vector < int > v;
int big;

int main(){
	
	cin >> n;
	cin >> m;
	
	//가로등 저장 
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	// 가로등이 1개인 경우 
	if(v.size() == 1){
		// 왼쪽 오른쪽 간격중 큰 값이 답. 
		big = max(v[0] , n - v[0]);
		cout << big;
		return 0;
	}
	
	//처음엔 처음~첫가로등간격, 마지막가로등~마지막간격 비교해서 큰것으로 초기화. 
	int big = max(v[0] , n-v[m-1]);
	
	//가로등 사이 간격에서 가로등 1개가 부담하는 간격 계산 후  big Update 
	for(int i = 1; i < v.size(); i++){
		
		int len = (int)ceil((v[i] - v[i-1]) / 2.0);
		
		if(big < len){
			big = len;
		}
	} 
	
	// 가로등 하나가 부담하는 사이 간격이 가장 높은것이 답 
	cout << big ;
} 
