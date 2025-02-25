#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int t;

int main(){
	
	cin >> t;
	while(t--){
		int temp[4][2];
		
		//�Է� 
		for(int i = 0; i < 4; i++){
			cin >> temp[i][0] >> temp[i][1];
		}
		
		vector<int> v;
		//���ü� �ִ� ��� ���� ���� ���ϱ� �� 6��.		
		for(int i = 0; i < 4; i++){
			for(int j = i+1; j < 4; j++){
				int len = abs(pow(temp[i][0] - temp[j][0], 2)) + abs(pow(temp[i][1] - temp[j][1], 2));
				v.push_back(len);
			}
		} 
		
		//�������� ���簢���̶�� �밢�� �ΰ��� �� �ڷ� ����. �밢���� �� ��⶧����. 
		sort(v.begin(), v.end());
		
		bool isRec = true; 
		int f_len = v[0];
		// 4���� �� Ȯ�� 
		for(int i = 1; i < 4; i++){
			if(f_len != v[i]){
				isRec = false;
				break;
			}
		}
		
		// 2���� �밢�� Ȯ��
		if(v[4] != v[5]){
			isRec = false;
		} 
		
		if(isRec){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}	
		
	}
}
