#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector < int> v;
int k;

//���
//people ��� ��  
//chicken ġŲ�� �� 

// ������ ��ʹ� pople���� ȸ���� ���� ���� ����. 
void dfs(int chicken, int people, int cnt){

	if(people == k){
		for(int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	else{
		for(int i = 0; i < chicken; i += cnt){
			sort(v.begin()+i, v.begin()+i+cnt);
		}
		dfs(chicken, people/2, cnt*2);
	}
} 

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	cin >> k;
	
	dfs(n, n, 2);
}
