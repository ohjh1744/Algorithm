#include <iostream>
using namespace std;

int dp[100001]; // iȸ�Ǹ� ���������� ���� ū �ο� 
int n;
int ans = 0;
int main(){
 	cin >> n;
 	for(int i = 1; i <= n; i++){
 		int start, end, cost;
 		cin >> start>> end >> cost;
 		dp[i] = cost;
 		
 		// i��° ȸ�Ǵ� i-1, i+1�� ������ ȸ�ǵ���� ��ġ�� �����Ƿ� 
 		// i��° ȸ�Ǹ� ������ �� �ִ� ���� i-2�� i-3. 
 		// ��ǻ� start �� end�� �ʿ䰡x. 
		if(i >= 3){
 			dp[i] = max(dp[i-2] + cost, dp[i-3] + cost);
		}
		
		if(ans < dp[i]){
			ans = dp[i];
		} 
		
	}
	
	cout << ans;

}
