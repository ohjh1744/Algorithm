#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[11][11];
int stDp[11][11];
int muDp[11][11];
int n; //전체영역크기 
int farmSize; // 농장크기 
int ans;

int main(){
   cin >> n;
   cin >> farmSize;
   
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         cin >> graph[i][j];
      }
   }
   
   //누적합 구하기
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         stDp[i][j] = stDp[i-1][j] + stDp[i][j-1] - stDp[i-1][j-1] + stDp[i][j]; 
         muDp[i][j] = muDp[i-1][j] + muDp[i][j-1] - muDp[i-1][j-1] + muDp[i][j]; 
      }
   } 
   
   // mu 
   for(int i = farmSize; i <=n; i++){
      for(int j = farmSize; j <= n; j++){
         int mushRoom = muDp[i][j] - muDp[i][j-k] - muDp[i-k][j] + muDp[i-k][j-k];
         int stone = stDp[i][j] - stDp[i][j-k] - stDp[i-k][j] + stDp[i-k][j-k];
         if(mushRoom > 0){
            continue;
         }
         if(stone > ans){
            ans = stone;
         }
         
      }
   }
   
   cout << ans;
   
}
