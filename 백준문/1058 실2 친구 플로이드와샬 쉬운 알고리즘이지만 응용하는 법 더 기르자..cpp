#include <iostream>
#include <algorithm>
using namespace std;

int graph[51][51];
int n;
int ans;

// �̹����� ��� �Է°��� 1 �� 2����Ǹ� 1-2 ,2-1 �Ѵ� Y. 
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			char c;
		    cin >> c;
	     	if(i == j){
	     		graph[i][j] = 0;
	     		continue;
	     	}
			if(c == 'N'){
				graph[i][j] = 9999999;
			}   
			else if(c == 'Y'){
				graph[i][j] = 1;
			}
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int temp = graph[i][k] + graph[k][j];
				if(temp < graph[i][j]){
					graph[i][j] = temp;
				}
			}
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			cout << graph[k][i] << " ";
		}
		cout << endl;
	}
	
	// �÷��̵�ͼ� �����  1�̸� ģ��, 2�̸� �ǳʼ� ģ�� 3�� �ǳʰǳ�ģ��~ 
	
	
	for(int i = 1; i <= n; i++){
		int ct = 0;
		for(int j = 1; j <=n; j++){
			if(graph[i][j] == 1 || graph[i][j] == 2){
				ct++;
			} 
		}
		ans = max(ans, ct);
	}
	
	cout << ans << "\n";
	
	
}
