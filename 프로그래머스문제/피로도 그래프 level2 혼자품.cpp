#include <string>
#include <vector>
using namespace std;


//혼자서 푼 문제 쉽게 풀어버림.
int canMaxNum = 0;

int visited[9]; // 던전별 방문 체크.

void dfs(int energy, int count, vector<vector<int>> v){
    if(canMaxNum < count){
        canMaxNum = count;
    }
    
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] <= energy && visited[i] == false){
            visited[i] = true;
            dfs(energy - v[i][1], count + 1, v);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    //dfs
    dfs(k, 0, dungeons);
    
    answer = canMaxNum;
    
    return answer;
}
