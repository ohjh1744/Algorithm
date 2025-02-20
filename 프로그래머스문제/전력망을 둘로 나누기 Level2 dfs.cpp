#include <string>
#include <vector>
#include <iostream>
using namespace std;


//블로그 참고해서 품. dfs로 풀려고는 했으나 기존의 dfs방식과는 독특한 방식
// 막 어렵진 않음. 
int visited[101];

int nodeNum; 

void dfs(int start, vector<vector<int>> wires){
    visited[start] = true;
    nodeNum++;
    for(int i = 0; i < wires.size(); i++){
        // 현재 start노드와 연결된 노드 확인, 방문처리 안되어있다면 dfs탐색.
        if(wires[i][0] == start && visited[wires[i][1]] == false){
            dfs(wires[i][1], wires);
        }
        if(wires[i][1] == start && visited[wires[i][0]] == false){
            dfs(wires[i][0], wires);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999;   
    
    for(int i = 0; i < wires.size(); i++){
        //초기화
        nodeNum = 0;
        vector<vector<int>> temp = wires;
        for(int i = 0; i <= n; i++){
            visited[i] = 0;
        }
        
        //순서대로 간선 하나씩 삭제하고 dfs 탐색.
        temp.erase(temp.begin() + i);
        dfs(1, temp);
        
        //삭제하고나서 생긴 두 그래프의 노드 차이 확인.
        int def = abs((n-nodeNum) - nodeNum);
        if(answer > def){
            answer = def;
        }
    }
    return answer;
}
