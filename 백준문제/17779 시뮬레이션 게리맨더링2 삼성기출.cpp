#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[21][21];
int visited[21][21]; //备开犬牢 
int n;
int ans = 9999999;
vector < pair < pair < int, int > , pair < int, int>  > > v; // x y d1 d2 历厘 
int one = 0, two  = 0, thr = 0, four = 0, five = 0;

void clear() //备开 努府绢 
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			visited[i][j] = 0;
		}
	}
	one = 0, two  = 0, thr = 0, four = 0, five = 0;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int y = 1; y <= n; y++){
		for(int x = 1 ; x <= n; x++){
			for(int d_1 = 1; d_1 <= n; d_1++){
				for(int d_2 = 1; d_2 <= n; d_2++){
					if(x+d_1 < 1 || x+d_1 > n || y-d_1 < 1 || y-d_1> n){
						continue;
					}
					if(x+d_2 < 1 || x+d_2 > n || y+d_2 < 1 || y+d_2 > n ){
						continue;
					}
					if(x+d_1+d_2 < 1 || x+d_1+d_2 > n || y-d_1+d_2 < 1 || y-d_1+d_2> n){
						continue;
					}
					if(x+d_2+d_1 < 1 || x+d_2+d_1 > n || y+d_2-d_1 < 1 || y+d_2-d_1 > n ){
						continue;
					}
					v.push_back({{y,x} , {d_1, d_2}});
				}
			}
		}
	}
	
	for(int i = 0; i < v.size(); i++){
		clear();
		int y = v[i].first.first;
		int x = v[i].first.second;
		int d1 = v[i].second.first;
		int d2 = v[i].second.second;
		
		// 5备开 版拌急 
		for(int z = 0; z <=d1; z++){
			visited[y-z][x+z] = 5;
		}
		for(int z = 0; z <=d2; z++){
			visited[y+z][x+z] = 5;
		}
		for(int z = 0; z <=d2; z++){
			visited[y-d1+z][x+d1+z] = 5;
		}
		for(int z = 0; z <=d1; z++){
			visited[y+d2-z][x+d2+z] = 5;
		}

		// 1备开  
		for(int c = 1; c <= y-1; c++){
			for(int r = 1; r <= x+d1 ; r++){
				if(visited[c][r] == 5 ){
				   break;
				}
				visited[c][r] = 1;
			}
		}	
		// 2备开
		for(int c = y+d2-d1; c >= 1; c--){
			for(int r = n; r >= x+d1+1 ; r--){
				if(visited[c][r] == 5 ){
				   break;
				}
				visited[c][r] = 2;
			}
		}
		// 3备开
		for(int c = n; c >= y; c--){
			for(int r = 1; r <= x+d2-1; r++){
				if(visited[c][r] == 5 ){
					break;
				}
				visited[c][r] = 3;
			}
		}
		//4备开 
		for(int c = y+d2-d1+1; c <= n; c++){
			for(int r = n; r >= x+d2 ; r--){
				if(visited[c][r] == 5 ){
				   break;
				}
				visited[c][r] = 4;
			}
		}		    
		
		// 备开喊 牢备 拌魂 
		  
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(visited[i][j] == 1){
					one = one + graph[i][j];
				}
				else if(visited[i][j] == 2){
					two = two + graph[i][j];
				}
				else if(visited[i][j] == 3){
					thr = thr + graph[i][j];
				}
				else if(visited[i][j] == 4){
					four = four + graph[i][j];
				}
				else if(visited[i][j] == 0 || visited[i][j] == 5){
					five = five + graph[i][j];
				}			
			}
		}
		int big = max(five , max(max(one, two) , max(thr, four)) );
		int small = min(five , min(min(one, two) , min(thr, four)) );
		ans = min(ans, big-small);
	}
	cout << ans ; 
}
