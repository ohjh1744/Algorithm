#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector < pair < int, pair < int , int > > > v;
int parent[1001];
int ans;
//�θ�ã�� 
int find_parent(int x)
{
	if(x == parent[x]){
		return x;
	}
	else{
		return parent[x] = find_parent(parent[x]);
	}
}

// �θ� ������ Ȯ�� 
bool Same_parent(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x == y){
		return true;
	}
	else{
		return false;
	}
}

// ���Ͽ��̶� ��ġ��� �� �θ� ���� �ٸ��� ��������� 
void merge(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x != y){
		parent[y] = x;
	}
	
}

// ũ�罺Į �˰��� mst �ּҺ��Ʈ��, ���Ͽ� ���ε�. 
//����� ���� ������� a, b��尡 ���� ����ȵǾ�������(�θ𰡴ٸ��� ) ����.
//��������� �Ÿ���. 
int main()
{
	cin >> n ;
	cin >> m;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a , b}});
	}
	
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	sort(v.begin(), v.end()); 
		
	for(int i = 0; i < v.size(); i++){
		if(Same_parent(v[i].second.first, v[i].second.second) == false){
			merge(v[i].second.first, v[i].second.second);
			ans = ans + v[i].first;
		}
	}

}
