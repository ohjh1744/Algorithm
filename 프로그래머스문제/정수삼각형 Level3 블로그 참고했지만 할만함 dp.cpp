#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //루트 값 세팅
    dp[0][0] = triangle[0][0];
    
    //가장자리의 최댓값 먼저 구하기
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    
    //가장자리를 제외한 내부 최댓값 구하기
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 1; j <= i-1; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    int hight = triangle.size()-1;
    //마지막 dp배열중에 가장 큰값 출력.
    for(int i = 0; i <= hight; i++){     
        if(answer < dp[hight][i]){
            answer = dp[hight][i];
        }     
    }
    
    return answer;
}
