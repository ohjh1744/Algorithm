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
		
		//입력 
		for(int i = 0; i < 4; i++){
			cin >> temp[i][0] >> temp[i][1];
		}
		
		vector<int> v;
		//나올수 있는 모든 변의 길이 구하기 총 6개.		
		for(int i = 0; i < 4; i++){
			for(int j = i+1; j < 4; j++){
				int len = abs(pow(temp[i][0] - temp[j][0], 2)) + abs(pow(temp[i][1] - temp[j][1], 2));
				v.push_back(len);
			}
		} 
		
		//정상적인 정사각형이라면 대각선 두개는 맨 뒤로 빠짐. 대각선이 더 길기때문에. 
		sort(v.begin(), v.end());
		
		bool isRec = true; 
		int f_len = v[0];
		// 4개의 변 확인 
		for(int i = 1; i < 4; i++){
			if(f_len != v[i]){
				isRec = false;
				break;
			}
		}
		
		// 2개의 대각선 확인
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
