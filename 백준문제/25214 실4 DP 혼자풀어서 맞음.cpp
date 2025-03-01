#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[200001];
int temp[200001];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
  
    int small = 0;
    dp[0] = 0;
  
    for (int i = 1; i < n; i++) {
        //만약 현제 인덱스가 그 전 배열중에서 가장 작은값보다 작다면 
  	    //전 배열의 가장 최대값이 현재 인덱스를 포함한 배열의 가장 최대값과 동일. 
        if (temp[small] > temp[i]) {
            small = i;
            dp[i] = dp[i-1];
        }
        // 아니라면 그전 dp값과 현재값에서 가장작은값을 뺀것과 비교해서 최대값 구하기. 
        else {
            dp[i] = max(dp[i-1], temp[i] - temp[small]);
        }
    }
  
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}
