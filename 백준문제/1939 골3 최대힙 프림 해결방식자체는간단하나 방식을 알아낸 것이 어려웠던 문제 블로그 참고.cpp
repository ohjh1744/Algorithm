#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

int n, m;
vector < pair < int, int > > v[10001];
int sn, en;
int dist[10001];
int visited[10001]; 
int ans = 1e9;

// �ذ�����ü�� �����ϳ� �� �ذ� ����� �˾Ƴ��� ���� ������� ���� 
// ������ mst�� ���ϴ� �˰��������� ������ ���ͽ�Ʈ��� ����ϱ⿡
// ���� ��������� �ٸ� �������� ������� ���ϱ� ����. 
// �ִ뽺�д�Ʈ���� ���ϴ� ��������  end��带 ó�� ������ ������ ����  dist�߿� ���� ���� ���� ����. 
void prim(int x){
	
    for(int i = 0; i < n; i++){
   	   dist[i] = 0;
    }
   	
	dist[x] = 1e9;
	
	priority_queue < pair< int, int> >  pq;
	
	pq.push({1e9, x});
	
	while(!pq.empty()){
		int cd = pq.top().first;
		int cx = pq.top().second;
		pq.pop();
		
		// �̹� ���� ���� 
		if(visited[cx] == true){
			continue;
		}
		
		visited[cx] = true;
		
		//���дװ�ο��� ���� �������� ����. 
		if(ans > cd){
			ans = cd;
		}
		//end������ ���� 
		if(cx == en){
			return;
		}
		
		for(int i = 0; i < v[cx].size(); i++){
			int nx = v[cx][i].first;
			int nd = v[cx][i].second;
			
			if(dist[nx] < nd){
				dist[nx] = nd;
				pq.push({nd, nx});
			}
		}
	}
}

int main(){
   cin >> n >> m;
   
   for(int i = 0; i < m; i++){
      int n1, n2, dist;
      cin >> n1 >> n2 >> dist;
      v[n1].push_back({n2, dist});
      v[n2].push_back({n1, dist});
   }
   
   
   cin >> sn >> en;
   
   prim(sn);
   
   cout << ans ;
   
   
}
