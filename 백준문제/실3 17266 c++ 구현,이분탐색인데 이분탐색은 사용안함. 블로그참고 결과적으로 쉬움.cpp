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
	
	//���ε� ���� 
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	// ���ε��� 1���� ��� 
	if(v.size() == 1){
		// ���� ������ ������ ū ���� ��. 
		big = max(v[0] , n - v[0]);
		cout << big;
		return 0;
	}
	
	//ó���� ó��~ù���ε��, ���������ε�~���������� ���ؼ� ū������ �ʱ�ȭ. 
	int big = max(v[0] , n-v[m-1]);
	
	//���ε� ���� ���ݿ��� ���ε� 1���� �δ��ϴ� ���� ��� ��  big Update 
	for(int i = 1; i < v.size(); i++){
		
		int len = (int)ceil((v[i] - v[i-1]) / 2.0);
		
		if(big < len){
			big = len;
		}
	} 
	
	// ���ε� �ϳ��� �δ��ϴ� ���� ������ ���� �������� �� 
	cout << big ;
} 
