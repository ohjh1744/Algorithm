#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501]; // y x

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // dp�迭 �ڱ��ڽ����� �ʱ�ȭ
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i][j] = triangle[i][j];
        }
    }
    
    //���̺� ù��°�� ������ ��ġ������ ���� ū�� ���ϱ�
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] += dp[i-1][0];
        dp[i][i] += dp[i-1][i-1];  
    }
    
    // �߰� dp�� ���
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 1; j < i; j++){
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    //������ �������Ȯ�ο��� ���� ū�� ���ϱ�
    for(int i = 0; i < triangle.size(); i++){
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    return answer;
}
