#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1. 가능한 경우의 수 구하기, 2. 가로가 세로보다 짧은 것 제외. 3. 가로와 세로가 최소 3 이상인지 확인하기
    int cnt = brown + yellow;
    vector< pair < int, int > > posible;
    
    for(int i = 1; i <= cnt; i++){
        if(cnt % i == 0 && i >= cnt/i && (i >= 3 && cnt/i >= 3)){
            posible.push_back({i, cnt/i});
        }
    }
    
     
    // 4. 가운데에 노란색격자가 들어갈수잇는지 확인하기
    
    for(int i = 0; i < posible.size(); i++){
        if((posible[i].first - 2) * (posible[i].second - 2) == yellow){
            answer.push_back(posible[i].first);
            answer.push_back(posible[i].second);
            break;
        }
    }
    
    return answer;
}
