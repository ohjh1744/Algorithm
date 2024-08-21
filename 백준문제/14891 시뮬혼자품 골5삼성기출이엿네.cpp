#include <iostream>
#include <vector>
using namespace std;

vector <int> wheel[5]; // 1 2 3 4톱니바퀴
bool b[5][2]; // (1~4)번째 바퀴의 왼쪽0 오른쪽1 일치하는지 안하는지 n극 s극 체크 
bool visited[5]; // 바퀴 체크 true는 이미 돌림 false는 아직 안돌림 

void dfs(int wh, int direct)
{
	visited[wh] = true;
	if(!visited[wh-1] && b[wh-1][1] && b[wh][0] == true){
		if(direct == 1){ // 시계방향일때 왼쪽에 있는 바퀴는 반시계방향으로 
			int num = wheel[wh-1].front();
			wheel[wh-1].erase(wheel[wh-1].begin());
			wheel[wh-1].push_back(num);
			dfs(wh-1 , -1);			
		}
		else if(direct == -1){ // 반시계방향일때 왼쪽에 있는 바퀴는 시계방향으로
			int num = wheel[wh-1].back();
			wheel[wh-1].pop_back();
			wheel[wh-1].insert(wheel[wh-1].begin(), num);
			dfs(wh-1 , 1);
		}
	}
	
	if(!visited[wh+1] && b[wh+1][0] && b[wh][1] == true){
		if(direct == 1){ // 시계방향일때 오른쪽에  있는 바퀴는 반시계방향으로
			int num = wheel[wh+1].front();
			wheel[wh+1].erase(wheel[wh+1].begin());
			wheel[wh+1].push_back(num);
			dfs(wh+1 , -1);			
		}
		else if(direct == -1){ //반시계방향일때 오른쪽에  있는 바퀴는 시계방향으로
			int num = wheel[wh+1].back();
			wheel[wh+1].pop_back();
			wheel[wh+1].insert(wheel[wh+1].begin(), num);
			dfs(wh+1 , 1);
		}
	}
}

void clear()
{
	for(int i = 1; i <= 4; i++){
		b[i][0] = false;
		b[i][1] = false;
		visited[i] = false;
	}
}

int k; 
int main()
{
	for(int i = 1; i <=4; i++){
		string s;
		cin >> s;
		for(int j = 0; j <8; j++){
		   if(s[j] == '1'){
			  wheel[i].push_back(1);
		    }
		    if(s[j] == '0'){
			  wheel[i].push_back(0);
		    }
	    }
	}
	
	cin >> k;
	for(int i = 0; i < k; i++){
		clear();
		int w , d;
		cin >> w >> d;
		if(wheel[1][2] != wheel[2][6]){
			b[1][1] = true;
			b[2][0] = true;
		}
		if(wheel[2][2] != wheel[3][6]){
			b[2][1] = true;
			b[3][0] = true;
		}
		if(wheel[3][2] != wheel[4][6]){
			b[3][1] = true;
			b[4][0] = true;
		}
		if(d == 1){ //시계방향 
			int num = wheel[w].back();
			wheel[w].pop_back();
			wheel[w].insert(wheel[w].begin(), num);
		}
		else if(d == -1){ // 반시계방향 
			int num = wheel[w].front();
			wheel[w].erase(wheel[w].begin());
			wheel[w].push_back(num);
		}
		dfs(w, d); 
		
	}
	int ans = 0;
	for(int i = 1; i <=4 ; i++){
		if(wheel[i][0] == 0){
			ans = ans + 0;
		}
		else if(wheel[i][0] == 1){
			if(i == 1){
				ans = ans + 1;
			}
			if(i == 2){
				ans = ans + 2;
			}
			if(i == 3){
				ans = ans + 4;
			}
			if(i == 4){
				ans = ans + 8;
			}
		}
	}
	cout << ans << endl; 
	
}
