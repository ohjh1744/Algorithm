#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 혼자서 풀때 테스트케이스 2개, 효율성 3개 틀림
// 결국 블로그 참고
// 개같은 문제
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    const int num = 1000000007;
    
    // 시작지점 1로 초기화
    dp[0][0] = 1;
    
    //웅덩이는 -1로 초기화
    for(int i = 0; i < puddles.size(); i++){
        int y = puddles[i][1] - 1;
        int x = puddles[i][0] - 1;
        dp[y][x] = -1;
    }
    
    // dp
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //웅덩이인경우 0으로 초기화.
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(i > 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % num; 
            }
            if(j > 0){
                 dp[i][j] = (dp[i][j] + dp[i][j-1]) % num; 
            }
        }
    }
    
    answer = dp[n-1][m-1];
    
    return answer;
}
