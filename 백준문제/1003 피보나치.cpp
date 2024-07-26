#include <iostream>
using namespace std;


int dp[41];

int fibonacci(int n)
{
   for(int i = 2; i <= n; i++){
   	dp[i] = dp[i-2] + dp[i-1];
   }
   return dp[n];	
}


int main()
{

	int n; 
	scanf("%d", &n);
	
	dp[0] = 0;
    dp[1] = 1;
	
	for(int i =0; i < n; i++){
	    int k;
	    cin >> k;
	    if(k==0){
	    	printf("%d %d\n", 1, 0);
		}
		else if(k==1){
	    	printf("%d %d\n", 0, 1);
		}
		else{
			fibonacci(k);
	        printf("%d %d\n", dp[k-1], dp[k]);
		}
	}
	
	
}



