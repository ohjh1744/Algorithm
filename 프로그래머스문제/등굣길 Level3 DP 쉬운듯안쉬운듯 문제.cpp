#include <iostream>
#include <string>
#include <vector>
using namespace std;


// ȥ�ڼ� Ǯ�� �׽�Ʈ���̽� 2��, ȿ���� 3�� Ʋ��
// �ᱹ ��α� ����
// ������ ����
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    const int num = 1000000007;
    
    // �������� 1�� �ʱ�ȭ
    dp[0][0] = 1;
    
    //�����̴� -1�� �ʱ�ȭ
    for(int i = 0; i < puddles.size(); i++){
        int y = puddles[i][1] - 1;
        int x = puddles[i][0] - 1;
        dp[y][x] = -1;
    }
    
    // dp
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //�������ΰ�� 0���� �ʱ�ȭ.
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
