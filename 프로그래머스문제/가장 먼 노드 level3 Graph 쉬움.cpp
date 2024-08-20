#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[20001];
vector <int> v[20001];

void bfs(int x)
{
    visited[x] = 1;
    queue < int > q;
    q.push(x);
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        for(int i = 0; i < v[cx].size(); i++){
            int nx = v[cx][i];
            if(!visited[nx]){
                visited[nx] = visited[cx] + 1;
                q.push(nx);
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    
    sort(visited, visited + n + 1 ,greater<int>());
    
    int far = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            far = visited[i];
        }
        if(far != visited[i]){
            break;
        }
        answer++;
    }
    
    return answer;
}


