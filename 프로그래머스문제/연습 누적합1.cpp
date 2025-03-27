#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[21][21];
int dp[21][21];
int n;
int k;
int ans;

int main(){
   cin >> n;
   cin >> k ;
   
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         cin >> graph[i][j];
      }
   }
   
   //������ ���ϱ�
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j]; 
      }
   } 
   
   // k������ ���� �ִ� ��������� �����������ִ���Ȯ�� 
   for(int i = k; i <=n; i++){
      for(int j = k; j <= n; j++){
         int people = dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k];
         if(ans < people){
            ans = people;
         } 
      }
   }
   
   cout << ans;
   
}
