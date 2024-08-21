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
	
	for(int b = 0; b < (1<<(n*m)); b++){ // ���δ� 0 ���δ� 1 
		int sum = 0;
		
		for(int i = 0; i < n; i++){   // ���η� ¥�� ���ڵ���  �� ���ϱ� 
		    int now = 0; 
			for(int j = 0; j <m; j++){
				int k = i*m + j;
				if((b & (1 << k)) == 0){ //���θ� 
				    cout << "�� " <<  b << " " << i << " " << j << " " << k << endl;
					now = (now * 10) + graph[i][j];
				}
				else{
					sum = sum + now;
					now = 0;
				}
			}
			sum = sum + now; //������ �������� �� �� 
		}
		
		for(int j = 0; j < m; j++){ //���η� ¥�� ���ڵ��� �� ���ϱ� 
			int now = 0;
			for(int i = 0; i < n; i++){
				int k = i*m + j;
				if((b & (1<< k)) != 0){ //���θ� 
				    cout << "�� " <<  b << " " << i << " " << j << " " << k << endl;
					now = (now* 10) + graph[i][j];
				}
				else{
					sum = sum + now;
					now = 0;
				}
			}

			sum = sum + now; //�� ���� �������� �� �� 
			
		}

		ans = max(ans, sum);
		
	}
	
	cout << ans << endl;
	
}
