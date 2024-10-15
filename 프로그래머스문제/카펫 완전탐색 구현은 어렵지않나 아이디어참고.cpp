#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1. ������ ����� �� ���ϱ�, 2. ���ΰ� ���κ��� ª�� �� ����. 3. ���ο� ���ΰ� �ּ� 3 �̻����� Ȯ���ϱ�
    int cnt = brown + yellow;
    vector< pair < int, int > > posible;
    
    for(int i = 1; i <= cnt; i++){
        if(cnt % i == 0 && i >= cnt/i && (i >= 3 && cnt/i >= 3)){
            posible.push_back({i, cnt/i});
        }
    }
    
     
    // 4. ����� ��������ڰ� �����մ��� Ȯ���ϱ�
    
    for(int i = 0; i < posible.size(); i++){
        if((posible[i].first - 2) * (posible[i].second - 2) == yellow){
            answer.push_back(posible[i].first);
            answer.push_back(posible[i].second);
            break;
        }
    }
    
    return answer;
}
