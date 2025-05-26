#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //웅덩이는 -1으로 초기화
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        dp[y][x] = -1;
    }
    
    //갈수있는 경로 계산
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){          
             
            // 집은 1로 설정 
            if(i == 1 && j == 1){
                dp[i][j] = 1;
                continue;
            }
            
            // 웅덩이는 무시
            if(dp[i][j] == -1){
                continue;
            }
                     
            // 왼쪽 x가 1이상인경우, 왼쪾이 웅덩이가아니라면
            if(j-1 >= 1){
                if(dp[i][j-1] != -1){
                    dp[i][j] += dp[i][j-1] % 1000000007;   
                }
            }
            
            //위쪽 y가 1이상인 경우, 위쪽이 웅덩이가 아니라면
            if(i-1 >= 1){
                if(dp[i-1][j] != -1){
                    dp[i][j] += dp[i-1][j] % 1000000007;
                }
            }        

        }
    }
    
    answer = dp[n][m] % 1000000007;
    
    return answer;
}
