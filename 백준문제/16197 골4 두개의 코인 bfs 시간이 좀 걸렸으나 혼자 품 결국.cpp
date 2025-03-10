#include <iostream>
#include <queue>
using namespace std;

char graph[21][21];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int n, m;
int ans  = -1;

//��4 ���̵� �� �־����� �ð� �����ؼ� ȥ��ǰ.
// �ݷʱ��� ȥ�� ã�� solve.
 

void bfs(int fy, int fx, int sy, int sx){
	
	queue < pair < pair < pair < int, int > , pair < int, int > > , int  > > q;
	q.push({{{fy, fx}, {sy, sx}}, 0});
	
	while(!q.empty()){
		int cfy = q.front().first.first.first;	
		int cfx = q.front().first.first.second;
		int csy = q.front().first.second.first;
		int csx = q.front().first.second.second;
		int ct = q.front().second;
		
		q.pop();
		
		if(ct > 9){
			break;
		}
				
		// 4���� �߿� �� �� �ִ� ���� �ֱ� 
		for(int i = 0; i < 4; i++){
			int nfy = cfy + dy[i];
			int nfx = cfx + dx[i];
			int nsy = csy + dy[i];
			int nsx = csx + dx[i];
			
			// ���� �����ϳ��� �������ٸ� ans ��. 
			if((nfy < 0 || nfx < 0 || nfy >= n || nfx >= m) && !(nsy < 0 || nsx < 0 || nsy >= n || nsx >= m)){
				ans = ct + 1;
				return; 
			}
			
			// ���� �����ϳ��� �������ٸ� ans ��.
			if(!(nfy < 0 || nfx < 0 || nfy >= n || nfx >= m) && (nsy < 0 || nsx < 0 || nsy >= n || nsx >= m)){
				ans = ct + 1;
				return; 
			}
			

			if((nfy < 0 || nfx < 0 || nfy >= n || nfx >= m) || (nsy < 0 || nsx < 0 || nsy >= n || nsx >= m) ){
				continue;
			}
			
			// ù��° ������ ������̳� ������ �ִ� ������ ���
			if(graph[nfy][nfx] == '.' || graph[nfy][nfx] == 'o'){
				// �ι�° ������ ���� ���� ���� �ڸ� �־��ֱ� 
				if(graph[nsy][nsx] == '#'){
					q.push({{{nfy, nfx}, {csy, csx}}, ct + 1});
				}
				// ������̳� �������� ��� ���� �ڸ� �־��ֱ� 
				else{
					q.push({{{nfy, nfx}, {nsy, nsx}} , ct + 1});
				}
			} 	
			// ù��° ������ ���� ��� 
			else{
				// �ι�° ������ ���� ���� ���� �ڸ� �־��ֱ� 
				if(graph[nsy][nsx] == '#'){
					q.push({{{cfy, cfx}, {csy, csx}}, ct + 1});
				}
				// ������̳� �������� ��� ���� �ڸ� �־��ֱ� 
				else{
					q.push({{{cfy, cfx}, {nsy, nsx}} , ct + 1});
				}
			}
		}
	}	
	
}


int main(){
	
	cin >> n >> m;
	
	int Coin[2][2];
	int curCoin = 0;
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 'o'){
				Coin[curCoin][0] = i;
				Coin[curCoin][1] = j;
				curCoin++;
			}
		}
	}
	
	bfs(Coin[0][0] , Coin[0][1], Coin[1][0], Coin[1][1]);
	
	cout << ans;
}
