#include <iostream>
#include <vector>
using namespace std;

int ans = 9999999;
int n;
int graph[10][10];

bool check[1000]; //���� �ڵ忡�� ����� �湮üũ
vector <int> p_pos; // ����ġ 


int visited[10][10];
int dy[4] = {0 , 0, 1, -1};
int dx[4] = {1, -1 , 0, 0};
bool b = true;  // true�� �ʼ����� false�� �� ���� 

void blossom() // �� 3���� �Ϻ��� �ʼ� �ִ��� Ȯ�� 
{
	for(int i = 0; i < p_pos.size(); i++){
		int y = p_pos[i] / n;
		int x = p_pos[i] % n;
		visited[y][x] = true;
		
		for(int j = 0; j < 4; j++){
			int ny = y + dy[j];
			int nx = x + dx[j];
			if(ny >= n || nx >= n || nx < 0 || ny < 0){
				b = false;
				continue;
			}
			if(visited[ny][nx]){
				b = false;
			}
			else if(!visited[ny][nx]){
				visited[ny][nx] = true;
			}
		}
		
	}		
}

void reset()
{
	b = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			visited[i][j] = false;
		}
	}
}

void combi(int itp, int ct)  // ����
{
	if(ct == 3){
		p_pos.clear();
		for(int i = 0; i < n*n; i++){
			if(check[i]){
				p_pos.push_back(i);
			}
		}
		
		reset();
		blossom();
		
		if(b == true){
			int ct = 0;
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					if(visited[j][k]){
						ct = ct + graph[j][k];
					}
				}
			}
			ans = min(ans, ct);
		}
		return;
	}
	
	for(int i = itp; i < n*n; i++){
		if(check[i]){
			continue;
		}
		check[i] = true;
		combi(i , ct+1);
		check[i] = false;
	}
}

int main()
{
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	
	combi(0 , 0);
	cout << ans << "\n";
	
}
