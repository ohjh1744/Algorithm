#include <iostream>
using namespace std;

bool graph[101][101];
int n;
int ans;

int main(){
	cin >> n;
	
	for(int i = 0; i< n; i++){
		int y, x;
		cin >> x >> y;
		
		for(int j = (100- y) - 9; j <= (100-y); j++ ){
			for(int z = x; z <= x + 9; z++){
				if(graph[j][z] == false){
					graph[j][z] = true;
					ans++;
				}
			}
		}
	} 
	
	cout << ans ;
}
