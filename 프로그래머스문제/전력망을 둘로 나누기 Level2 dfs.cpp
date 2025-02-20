#include <string>
#include <vector>
#include <iostream>
using namespace std;


//��α� �����ؼ� ǰ. dfs�� Ǯ����� ������ ������ dfs��İ��� ��Ư�� ���
// �� ����� ����. 
int visited[101];

int nodeNum; 

void dfs(int start, vector<vector<int>> wires){
    visited[start] = true;
    nodeNum++;
    for(int i = 0; i < wires.size(); i++){
        // ���� start���� ����� ��� Ȯ��, �湮ó�� �ȵǾ��ִٸ� dfsŽ��.
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
        //�ʱ�ȭ
        nodeNum = 0;
        vector<vector<int>> temp = wires;
        for(int i = 0; i <= n; i++){
            visited[i] = 0;
        }
        
        //������� ���� �ϳ��� �����ϰ� dfs Ž��.
        temp.erase(temp.begin() + i);
        dfs(1, temp);
        
        //�����ϰ��� ���� �� �׷����� ��� ���� Ȯ��.
        int def = abs((n-nodeNum) - nodeNum);
        if(answer > def){
            answer = def;
        }
    }
    return answer;
}
