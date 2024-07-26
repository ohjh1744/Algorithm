#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int temp[1000];

int main()
{
	cin >> n >> l;
	for(int i = 0; i <n; i++){
		cin >> temp[i];
	}
	
	sort(temp, temp+n);
	int start = temp[0];
	
	int tape = 0;
	for(int i = 1 ; i < n; i++){
		if(l <= temp[i] - start){ // 길이가 사이길이보다 짧거나 같다면 이전 누수된 곳까지만 테이프 붙이기 가능 
			tape++;
			start = temp[i];
		}
	}
	cout << tape + 1 << endl;  // 마지막 지점 테이프 안붙엿으므로 
}
