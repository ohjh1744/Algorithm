#include <iostream>
#include <vector>
#include <queue>
#define maxValue 300000000
using namespace std;

int dist[801];
vector <pair < int , int > > v[801];
int n, e;
int a, b;

// Ǫ�� ����� ���� ������ ȥ�ڼ� solve 
void djstra(int x){
	
	for(int i = 0; i <= n; i++){
		dist[i] = maxValue;
	}
	dist[x] = 0;
	
	priority_queue< pair < int, int > , vector < pair < int, int > > , greater < pair < int, int > > > pq;
	
	pq.push({0, x});
	
	while(!pq.empty()){
		int cx = pq.top().second;
		int cd = pq.top().first;
		pq.pop();
		
		//�̹� �ִܰ�ΰ� ������ ��� 
		if(dist[cx] < cd){
			continue;
		}
		
		for(int i = 0; i < v[cx].size(); i++){
			int nx = v[cx][i].first;
			int nd = v[cx][i].second + cd;
			
			if(dist[nx] > nd){
				dist[nx] = nd;
				pq.push({nd, nx});
			}
		}
	}
}

void clear(){
	for(int i = 0; i <= n; i++){
		dist[i] = maxValue;
	}
}

int main(){
	
	cin >> n >> e;
	
	for(int i = 0; i < e; i++){
		int from, to , dist;
		cin >> from >> to >> dist;
		v[from].push_back({to, dist});
		v[to].push_back({from, dist});
	}
	
	cin >> a >> b;
	
	//1~a�� 1~b�� �ִ� �Ÿ����ϱ�
	int distA, distB;
	djstra(1);	
	distA = dist[a];	
	distB = dist[b];
	clear();
	
	// a~b�� �ִ� �Ÿ� ���ϱ� 
	int distAB;
	djstra(a);
	distAB = dist[b];
	clear();
	
	// a~n, b~n �ִ� �Ÿ����ϱ� 
	int distAN, distBN;
	djstra(a);
	distAN = dist[n];
	clear();	
	djstra(b);
	distBN = dist[n];
	clear();
	
	// 1~a~b~n�� 1~b~a~n �� ��� ��.
	int min1 = distA + distAB + distBN;
	int min2 = distB + distAB + distAN;
	int ans = min(min1, min2);
	
	// maxValue���� ũ�� ��ΰ� ���ٴ� �̾߱� 
	if(ans >= maxValue){
		cout << -1;
	} 
	else{
		cout << ans;
	}
	
		
}
