#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

// index 0은 사용하지 않음으로 배열을 하나 더 추가
bool visited[10000]; 
vector<int> graph[10000];

void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
	{
		int y = graph[x][i];
		if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            dfs(y); // 재귀적으로 방문
	}
}

bool visited_bfs[10000];

void bfs(int start) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    visited_bfs[start] = true; // 첫 노드를 방문 처리

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
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
    int num_1; //2번쨰줄 1번쨰 노드입력 
    int num_2; // 2번째 줄 2번째 연결되는 노드입력 
    
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
        cout << "첫번쨰 노드: " <<graph[1][i] << " "; 	
	}
	cout<< endl;
	
	for(int i =0; i < graph[2].size(); i++){
        cout << "두 번쨰 노드: " <<graph[2][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[3].size(); i++){
        cout << "세 번쨰 노드: " <<graph[3][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[4].size(); i++){
        cout << "네 번쨰 노드: " <<graph[4][i] << " "; 	
	}
	cout<< endl;
	for(int i =0; i < graph[5].size(); i++){
        cout << "다섯 번쨰 노드: " <<graph[5][i] << " "; 	
	}
	for(int i =0; i < graph[6].size(); i++){
        cout << "여섯 번쨰 노드: " <<graph[6][i] << " "; 	
	}
	for(int i =0; i < graph[7].size(); i++){
        cout << "칠곱  번쨰 노드: " <<graph[7][i] << " "; 	
	}
		
	cout << endl;
	dfs(st);
	cout << endl;
	bfs(st);
	
	
    
}
