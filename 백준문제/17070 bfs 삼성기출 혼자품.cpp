#include <iostream>
#include <queue>
using namespace std;

int graph[17][17];
int dy[3] = {0,1,1}; //������ �밢�� �Ʒ� 
int dx[3] = {1,1,0}; //  0      1     2
int ct;
int n;

void bfs()
{
	queue < pair < pair < int, int >, int > > q; //y x ���¹��� 
	q.push({{1, 2} , 0});
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cd = q.front().second;
		q.pop();
		
		if( cy == n && cx == n){
			ct++;
		}
		
		for(int i = 0; i < 3; i++){
			if(cd == 0){ // �������϶� �Ʒ����� 
				if(i == 2){
					continue;
				}
			}
			else if( cd == 2){ // �Ʒ��϶� ������ ���� 
				if( i == 0){
					continue;
				}
			}
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			// ũ�⸦ �Ѿ�ų� �������� �����ִٸ� �Ұ� 
			if(ny < 1 || nx < 1 || ny > n || nx > n || graph[ny][nx] == 1){
			   continue;
		    }
		    if(i == 1){ //�������̳� �Ʒ��� �����ִٸ� �밢�� �Ұ� 
		    	if(graph[cy + dy[0]][cx + dx[0]] == 1 || graph[cy + dy[2]][cx + dx[2]] == 1){
		    		continue; 
				}
			}
			q.push({{ny, nx}, i}); 
			
		}
	}
}



int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	bfs();
	cout << ct << "\n";
	
}
