#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[4][4];
int ans;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			graph[i][j] = s[j] - '0';
		}
	}
	
	for(int b = 0; b < (1<<(n*m)); b++){ // 가로는 0 세로는 1 
		int sum = 0;
		
		for(int i = 0; i < n; i++){   // 가로로 짜른 상자들의  합 구하기 
		    int now = 0; 
			for(int j = 0; j <m; j++){
				int k = i*m + j;
				if((b & (1 << k)) == 0){ //가로면 
				    cout << "가 " <<  b << " " << i << " " << j << " " << k << endl;
					now = (now * 10) + graph[i][j];
				}
				else{
					sum = sum + now;
					now = 0;
				}
			}
			sum = sum + now; //한행이 끝낫으면 또 합 
		}
		
		for(int j = 0; j < m; j++){ //세로로 짜른 상자들의 합 구하기 
			int now = 0;
			for(int i = 0; i < n; i++){
				int k = i*m + j;
				if((b & (1<< k)) != 0){ //세로면 
				    cout << "세 " <<  b << " " << i << " " << j << " " << k << endl;
					now = (now* 10) + graph[i][j];
				}
				else{
					sum = sum + now;
					now = 0;
				}
			}

			sum = sum + now; //한 열이 끝낫으면 또 합 
			
		}

		ans = max(ans, sum);
		
	}
	
	cout << ans << endl;
	
}
