#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> v;
int ans = 0;
int minValue;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	minValue = v[0];
	
	for(int i = 1; i < v.size(); i++){
		//�������ִ� �̵� ������Ʈ 
		if(v[i] > minValue){
			ans = max(ans, v[i] - minValue);
		}
		//�ּҰ� ������Ʈ 
		else{
			minValue = v[i];
		}
	}
	
	cout << ans;
} 
