#include <iostream>
using namespace std;
//https://jow1025.tistory.com/118 Âü°í 
int graph[501][501];
int n, m;
int ans;
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1][num2] = true;
	}


	for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }
	
	bool b;
	
	for(int i = 1; i <= n; i++){
		b = true;
		for(int j = 1; j <= n; j++){
			if(i == j || graph[i][j] == 1){
				continue;
			}
			if(graph[i][j] == 0){
				if(graph[j][i] == 0){
					b = false;
				}
			}
		}
		if(b == true){
			ans++;
		}
	}
	cout << ans << endl;
}
