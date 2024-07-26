#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int  y, x, t;  //y = r , x = c
int graph[51][51];
int dx[4] = {1, -1 , 0 , 0};
int dy[4] = {0 , 0, 1, -1};
vector < pair < int , int > > ac; // ����û�ұ� �ִ� �� �� �Ʒ� ���� 
int ans;

void bfs()
{
	queue < pair < int, int > > q;
	vector < pair < int , int > > v; 
	// �̼������ִ� ���� ���� 
	for(int i = 1; i <= y; i++){  
		for(int j = 1; j <=x; j++){
			if(graph[i][j] > 0){
				v.push_back({i, j});
			}
		}
	}
	
	for(int i = 0; i < v.size(); i++){
		q.push({v[i].first, v[i].second});
	}
	
	vector < pair < pair < int , int > , int > > cal; // ���߿� �Ѳ����� Ȯ���� 
	
	while(!q.empty()){   // 1�ʿ� Ȯ��Ǵ� �̼����� ���� 
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		int dir = 0;
		for(int i = 0; i < 4; i++){
			int ny = cy+ dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > y || nx > x || graph[ny][nx] == -1){
				continue;
			}
			dir++;
			cal.push_back({{ny, nx} , graph[cy][cx] / 5});	
		}
		cal.push_back({{cy, cx} , -((graph[cy][cx] / 5) * dir)});
	}
	
	for(int i = 0; i < cal.size(); i++){
		int yy = cal[i].first.first;
		int xx = cal[i].first.second;
		int a = cal[i].second;
		graph[yy][xx] = graph[yy][xx] + a;
	}
	
}

void airclean()
{
	int top_ac_y = ac[0].first;
	int top_ac_x = ac[0].second;
	
	int bottom_ac_y = ac[1].first;
	int bottom_ac_x = ac[1].second;
	
	//�ݽð���� ������ 
	for(int i = top_ac_y; i >= 2; i--){
		graph[i][1] = graph[i-1][1];
		if(graph[i][1] == graph[top_ac_y][1]){
			graph[i][1] = -1; //����û���� ��� ǥ�ø� �ؼ� �����ֱ� ���߿� 0�̻� ���  
		}
	}
		
	//�ݽð���� ������ 
	for(int i = 1; i <= x-1; i++){
		graph[1][i] = graph[1][i+1];
	}
	
	// �ݽð���� ������ ��
	for(int i = 1; i < top_ac_y; i++){
		graph[i][x] = graph[i+1][x];
	}
	
	// �ݽð���� �Ʒ��� ��
	for(int i = x; i >= 2; i--){
		graph[top_ac_y][i] = graph[top_ac_y][i-1];
		if(graph[top_ac_y][i] == -1){
			graph[top_ac_y][i] = 0;
		}
	} 
	//////////////////////////////////////////////
	//�ð���� ������
	for(int i = bottom_ac_y; i < y; i++){
		graph[i][1] = graph[i+1][1];
		if(graph[i][1] == graph[bottom_ac_y][1]){
			graph[i][1] = -1;
		}
	} 
	
	// �ð���� �Ʒ�����
	for(int i = 1; i <= x-1; i++ ){
		graph[y][i] = graph[y][i+1];
	} 
	
	//�ð���� ��������
	for(int i = y; i > bottom_ac_y; i--){
		graph[i][x] = graph[i-1][x];
	} 

	//�ð���� ������
	for(int i = x; i >=2; i--){
		graph[bottom_ac_y][i] = graph[bottom_ac_y][i-1];
		if(graph[bottom_ac_y][i] == -1){
			graph[bottom_ac_y][i] = 0;
		}
	} 

	
}

int main()
{
	cin >> y >> x >> t;
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <=x; j++){
			cin >> graph[i][j];
			if(graph[i][j] == -1){
				ac.push_back({i, j});
			}
		}
	}
	
	for(int i = 0; i < t; i++){
		bfs();
		airclean();
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <=x; j++){
			if(graph[i][j] > 0){
				ans = ans + graph[i][j];
			}
		}
	}
	cout << ans << "\n";
	
	
}
