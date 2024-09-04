#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// ����� ������ �ƴϳ� ���̵�� ã�� �����ϱ� 

int minTemp[10001];
int maxTemp[10001];

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        int x = sizes[i][0];
        int y = sizes[i][1];
        if(x > y){
            maxTemp[i] = x;
            minTemp[i] = y;
        }
        else{
            maxTemp[i] = y;
            minTemp[i] = x;
        }
    }
    
    sort(minTemp + 0, minTemp + sizes.size());
    sort(maxTemp + 0, maxTemp + sizes.size());
    
    answer = minTemp[sizes.size()-1] * maxTemp[sizes.size()-1];
    
    
    return answer;
}
