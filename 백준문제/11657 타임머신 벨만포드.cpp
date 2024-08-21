#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, c;
vector < pair < int , pair < int, int > > > v;
long long dist[501];
// ll �̿��������� �ִ밪�� ���� ����Ŭ �߻��� int�� ���
// �������� 6000��, 1 -> 2 -> *** -> n -> 1 (�������� -10000)���, -60000000 *�ݺ��� ��ŭ �ִܱ��� ��Ӻ�ȭ. 

// ��������� ������ ����(n-1)��ŭ �ݺ��ϰ�, �������� �׷����� n-1�ȿ� �̹� ���� ����������,
// ���������α׷���(���ǻ���Ŭ, ���ǻ���Ŭ)�� ��� ���� ��ȭ~. 

bool bellmanFord(int start)
{
	dist[start] = 0;
	
	// n-1 ���� �ݺ� 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < v.size(); j++){
			int fr = v[j].first;
			int to = v[j].second.first;
			int d = v[j].second.second;
			
			if(dist[fr] == 1e9){
				continue;
			}
			
			if(dist[to] > dist[fr] + d){
				dist[to] = dist[fr] + d;
				
				if(i == n){
					return true;   //n��°���� �� ���̺���ȴٸ� ����Ŭ�� �߻��޴ٴ°�. 
				}
			}
		}
		
		cout << dist[1] << " " << dist[2] << " " << dist[3] << "\n"; 
	}
	
	return false;
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		v.push_back({a, { b, c}});
	}
	
	for(int i = 1; i <= n; i++){
		dist[i] = 1e9;
	}
	
	bool b = bellmanFord(1);
	
	if(b == true){
		cout << -1;
		return 0;
	} 
	else{
		for(int i = 2; i <= n; i++){
			if(dist[i] == 1e9){
				cout << -1 << "\n";
			}
			else{
				cout << dist[i] << "\n";
			}
		}
	}
	
}
