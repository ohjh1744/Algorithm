#include <iostream>
#include <map>
using namespace std;

int n;
map<int , int >mp;
int graph[2187][2187];

void dfs(int y, int x , int size){
	//���̰� ��� �������� �̷�����ִ��� Ȯ�� 
	int f_num = graph[y][x];
	bool isSame = true;
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(f_num != graph[i][j]){
				isSame = false;
				break;
			}
		}
	}
	
	//���ٸ� 
	if(isSame == true){
		mp[f_num]++;
		return;
	}
	
	//�ƴ϶�� 9���� ���� ũ��� ����
	//���� 
	dfs(y, x, size/3);
	dfs(y, x+(size/3), size/3);
	dfs(y, x+((size/3)*2), size/3);
	//�߰���
	dfs(y+(size/3), x, size/3);
	dfs(y+(size/3), x+(size/3), size/3);
	dfs(y+(size/3), x+((size/3)*2), size/3);
	//�������� 
	dfs(y+((size/3)*2), x, size/3);
	dfs(y+((size/3)*2), x+(size/3), size/3);
	dfs(y+((size/3)*2), x+((size/3)*2), size/3); 
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	
	mp[-1] = 0;
	mp[0] = 0;
	mp[1] = 0;
	
	dfs(0, 0, n); 
	
	cout << mp[-1] <<"\n"; 
	cout << mp[0] <<"\n"; 
	cout << mp[1] <<"\n"; 
}
