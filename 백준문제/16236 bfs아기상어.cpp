#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[21][21];
int visited[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int bs_size = 2;
int eat_ct;
int near_d;
int near_x;
int near_y;
bool b = false; // ���̻� ���� ���� �ִ��� Ȯ��
int bs_y;  //�Ʊ��� ��ġ ����. 
int bs_x; 
int ans;

// �� ������ �Ÿ���, y��, x������ �ּ������� �����ϸ� ����
 
void bfs(int y, int x) //���尡������ã�� 
{
	visited[y][x] = true;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //������������ 
	queue< pair< int, pair < int, int > > > q; //�̵����ɱ���
	q.push({0, {y, x}});
	while(!q.empty()){
		int cd = q.front().first;
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nd = cd + 1;
			int ny = cy + dy[i];
			int nx = cx + dx[i];			
			if(ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(!visited[ny][nx] && graph[ny][nx] <= bs_size){   // �Ʊ���� ũ�Ⱑ ���ų� ������ ĭ������������. 
				q.push({nd,{ny ,nx}});
				visited[ny][nx] = true;
				if(graph[ny][nx] > 0 && graph[ny][nx] < bs_size){ //�Ʊ���� ũ�Ⱑ ������ ������������ pq�� ����. 
					pq.push({nd,{ny ,nx}});
				} 
			}			
		}				
	}
	
	if(pq.empty()){ //���� ���̰� ���ٸ� 
		b = true;
		return;
	}
	
	near_d = pq.top().first;
	near_y = pq.top().second.first;
	near_x = pq.top().second.second;
}

void reset()
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			visited[i][j] = false;
		}
	}
	graph[bs_y][bs_x] = 0; //���� �Ʊ�����ġ 0���ιٲ���. 
	bs_y = near_y;  //�Ʊ�����ġ �ٲ��� 
	bs_x = near_x; 	
	graph[bs_y][bs_x] = 9; //�Ʊ�����ġ 9�ιٲ���.  
}


int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 9){
				bs_y = i;
				bs_x = j;
			}
		}
	}
	
	while(1){
		bfs(bs_y, bs_x);		
		if(b){			
			break;
		}
		ans = ans + near_d;
		eat_ct++; // ���� ���̰����÷��ֱ� 
		if(eat_ct == bs_size){ 
			bs_size++;
			eat_ct = 0;
		}
		reset();
	}
	
	cout << ans << "\n"; 
	
}
