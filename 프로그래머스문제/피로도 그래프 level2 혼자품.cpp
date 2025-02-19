#include <string>
#include <vector>
using namespace std;


//ȥ�ڼ� Ǭ ���� ���� Ǯ�����.
int canMaxNum = 0;

int visited[9]; // ������ �湮 üũ.

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
