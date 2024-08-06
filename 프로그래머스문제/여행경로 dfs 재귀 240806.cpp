#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<string> canGo;
vector<vector<string>> temp;

void dfs(vector<vector<string>> tickets, string cnode, int cnt, bool used[]) {
    if (cnt == tickets.size()) {
        temp.push_back(canGo);
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == cnode && !used[i]) {
            canGo.push_back(tickets[i][1]);
            used[i] = true;
            dfs(tickets, tickets[i][1], cnt + 1, used);
            used[i] = false;
            canGo.pop_back();
        }
    }
}


vector<string> solution(vector<vector<string>>tickets) {
    bool used[tickets.size()];
    for(int i = 0; i < tickets.size(); i++){
    	used[i] = 0;
	} 

    dfs(tickets, "ICN", 0, used); 
    sort(temp.begin(), temp.end());
    
    answer.push_back("ICN");
    for(int i = 0; i < temp[0].size(); i++){
    	answer.push_back(temp[0][i]);
	}
    
    return answer;
}
