#include <string>
#include <vector>

using namespace std;
int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = 99999;
            }
        }
    }
    
    for(int i = 0; i < results.size() ; i++){
        graph[results[i][0]][results[i][1]] = 1;
        graph[results[i][1]][results[i][0]] = -1;
    }   
    
    for(int z = 1; z <= n; z++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][z] == 1 && graph[z][j] == 1){
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
            }
        }
    }
    
    bool cantRank = false;
    for(int i = 1; i <= n; i++){
        cantRank = false;
        for(int j = 1; j <= n; j++){
           if(graph[i][j] == 99999){
               cantRank = true;
               break;
           }
        }
        if(cantRank == false){
            answer++;
        }
    }
    
  
    
    
    return answer;
}
