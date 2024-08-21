#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n ; 
vector <int> calcul; // �� ����� ������ ��� 
vector <int> v; //�����Է� 
bool visited[8];

int ans = 0;
 
void dfs()
{
	if(calcul.size() == n){
		int temp = 0;
		for(int i = 0; i < calcul.size()-1; i++){
			temp = temp + abs(calcul[i] - calcul[i+1]); 
		}
		ans = max( ans, temp);
		return;
	}
	
	for(int i = 0 ; i < v.size(); i++){
		if(!visited[i]){
			visited[i] = true;
			calcul.push_back(v[i]);
			dfs();
			calcul.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	int num;
	
	for(int i = 0 ; i < n; i++){
		cin >> num;
		v.push_back(num);
	}
	dfs();
	cout << ans << endl;
}
