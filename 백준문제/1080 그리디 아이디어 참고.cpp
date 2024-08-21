#include <iostream>
using namespace std;

int graph1[51][51];
int graph2[51][51];
int n, m;
int ct ;
int main()
{
	cin >> n  >> m;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d" , &graph1[i][j]);
		}
	}
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d" , &graph2[i][j]);
		}
	} 
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			if(i+1 > n || i+2 > n || j+1 > m || j+2 > m || graph1[i][j] == graph2[i][j]){
				continue;
			}
			ct++;
	
			for(int a = i; a < i+3; a++){ 
				for(int b = j; b < j+3; b++){
					if(graph1[a][b] == 0){
						graph1[a][b] = 1;
					}
					else{
						graph1[a][b] = 0;
					}
				}
			}
			
						
		}
	}
	


	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			if(graph1[i][j] != graph2[i][j]){
				cout << "-1" ;
				return 0;
			}
		}
	}
	
	cout << ct << endl;
	
}
