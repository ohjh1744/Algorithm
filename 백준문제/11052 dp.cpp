#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = max(dp[1] + dp[1] , arr[2]);
	for(int i = 3; i <= n; i++){
		dp[i] = arr[i];
		int ct = i/2;
		int j = i-1;
		while(ct--){
			dp[i] = max(dp[i] , dp[j] + dp[i-j]);
			j = j-1;
		}
	}
	cout << dp[n] << endl;
}

//https://dontdiethere.tistory.com/86
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int dp[MAX];
int cards[MAX];

int main(){
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++)
        cin >> cards[i];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i] = max(dp[i], dp[i-j] + cards[j]);
    
    cout << dp[n] << endl;
    
    return 0;
}
