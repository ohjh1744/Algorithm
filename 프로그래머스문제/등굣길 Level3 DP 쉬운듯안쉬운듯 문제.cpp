#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //�����̴� -1���� �ʱ�ȭ
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        dp[y][x] = -1;
    }
    
    //�����ִ� ��� ���
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){          
             
            // ���� 1�� ���� 
            if(i == 1 && j == 1){
                dp[i][j] = 1;
                continue;
            }
            
            // �����̴� ����
            if(dp[i][j] == -1){
                continue;
            }
                     
            // ���� x�� 1�̻��ΰ��, �ަU�� �����̰��ƴ϶��
            if(j-1 >= 1){
                if(dp[i][j-1] != -1){
                    dp[i][j] += dp[i][j-1] % 1000000007;   
                }
            }
            
            //���� y�� 1�̻��� ���, ������ �����̰� �ƴ϶��
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
