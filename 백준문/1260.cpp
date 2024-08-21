#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

// index 0�� ������� �������� �迭�� �ϳ� �� �߰�
bool visited[10000]; 
vector<int> graph[10000];

void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) // ������ ��� �����ŭ Ž��
	{
		int y = graph[x][i];
		if (!visited[y]) // �湮���� �ʾ����� �� visited�� False�� �� not�� ���ָ� True�� �ǹǷ� �Ʒ� dfs ����
            dfs(y); // ��������� �湮
	}
}

bool visited_bfs[10000];

void bfs(int start) {
    queue<int> q;
    q.push(start); // ù ��带 queue�� ����
    visited_bfs[start] = true; // ù ��带 �湮 ó��

    // ť�� �� ������ �ݺ�
    while (!q.empty()) {
        // ť���� �ϳ��� ���Ҹ� �̾� ���
        int x = q.front();
        q.pop();
        cout << x << ' ';
        // �ش� ���ҿ� �����, ���� �湮���� ���� ���ҵ��� ť�� ����
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited_bfs[y]) {
                q.push(y);
                visited_bfs[y] = true;
            }
        }
    }
}



int main(void)
{
    int node;
    int line;
    int st;
    int num_1; //2������ 1���� ����Է� 
    int num_2; // 2��° �� 2��° ����Ǵ� ����Է� 
    
    cin >> node;
    cin >> line;
    cin >> st;
    
    vector<int> v[node+1];
    
	for(int i = 0; i<line; i++){
    	int n=0;
		cin >> num_1;
		cin >> num_2;
		v[num_1].push_back(num_2);	
		v[num_2].push_back(num_1);	  
	}
	
	for(int i = 0; i< node; i++){
	  sort(v[i+1].begin(), v[i+1].end());	
	}
	
    for(int i=1; i <= node; i++){
		for(int j=0; j<v[i].size(); j++){
			 graph[i].push_back(v[i][j]);
		}
	}
	
	for(int i =0; i < graph[1].size(); i++){
        cout << "ù���� ���: " <<graph[1][i] << " "; 	
	}
	cout<< endl;
	
	for(int i =0; i < graph[2].size(); i++){
        cout << "�� ���� ���: " <<graph[2][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[3].size(); i++){
        cout << "�� ���� ���: " <<graph[3][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[4].size(); i++){
        cout << "�� ���� ���: " <<graph[4][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[5].size(); i++){
        cout << "�ټ� ���� ���: " <<graph[5][i] << " "; 	
	}
	for(int i =0; i < graph[6].size(); i++){
        cout << "���� ���� ���: " <<graph[6][i] << " "; 	
	}
	for(int i =0; i < graph[7].size(); i++){
        cout << "ĥ��  ���� ���: " <<graph[7][i] << " "; 	
	}
		
	cout << endl;
	dfs(st);
	cout << endl;
	bfs(st);
	
	
    
}
