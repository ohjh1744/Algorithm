#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int h, w; // ���� , ���� 
int graph[502][502];

int count; // ������ ���ϼ����ִ� ���� 
int ans;  //������ Ȯ���� ���̴� ���� 

void bfs(int y, int x)
{
	queue< pair < int , int > > q;
	q.push({y, x+1});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if(graph[cy][cx] == 1 || cx >= w){  //�ᱹ �翷�� ���������� �׾��� count���� ������ ���ϼ��ִ�. 
			if(graph[cy][cx] == 1){
				ans = ans + count;
				count = 0;
				break;
			}
			else if(cx >= w){         // �����ʳ����� ���µ� ���� �������, count�� ���� ������ �ɼ�����. 
				count = 0;
				break;
			}
		}
		
		count++;
		int ny = cy;
		int nx = cx + 1;
		q.push({ny, nx});
	}
}

int main()
{
	cin >> h >> w;
	for(int i = 1; i <= w; i++){
		int r;
		cin >> r;
		int n = 0;
		while(n< r){
			graph[h-n][i] = 1;
			n++;
		}
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(graph[i][j] == 1){
				bfs(i, j);
			}
		}
	}
	cout << ans << "\n";
	
}
