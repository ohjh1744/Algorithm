#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int arr[200001];
int dp[200001];

int main(){
   
   cin >> n;
   
   for(int i = 1; i <= n ; i++){
   	 cin >> arr[i];
   }
   
   dp[n] = 1;
   
   for(int i = n-1; i >=1; i--){
   	 if(i + (arr[i] + 1) > n ){
   	 	dp[i] = 1;
	 }
	 else{
	 	dp[i] = 1 + dp[i + (arr[i] + 1)];
	 }
   }
   
   for(int i = 1; i <= n ; i++){
   	 cout << dp[i] << " ";
   }
   

}
