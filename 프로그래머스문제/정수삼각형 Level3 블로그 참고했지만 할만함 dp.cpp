#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //��Ʈ �� ����
    dp[0][0] = triangle[0][0];
    
    //�����ڸ��� �ִ� ���� ���ϱ�
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    
    //�����ڸ��� ������ ���� �ִ� ���ϱ�
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 1; j <= i-1; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    int hight = triangle.size()-1;
    //������ dp�迭�߿� ���� ū�� ���.
    for(int i = 0; i <= hight; i++){     
        if(answer < dp[hight][i]){
            answer = dp[hight][i];
        }     
    }
    
    return answer;
}
