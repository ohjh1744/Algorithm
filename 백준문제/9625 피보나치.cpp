#include <iostream>
#include <string>
using namespace std;

int a[46], b[46];

int dp_a(int n)
{
   for(int i = 3; i <= n; i++){
   	a[i] = a[i-2] + a[i-1];
   }
   return a[n];	
}

int dp_b(int n)
{
   for(int i = 3; i <= n; i++){
   	b[i] = b[i-2] + b[i-1];
   }
   return b[n];	
}



int main()
{
	a[1] = 0;
    a[2] = 1;
    b[1] = 1;
    b[2] = 1;
    
    int k;
    cin >> k;
    
    if(k == 1){
       cout << a[1] << " " << b[1];	
       return 0;
	}
	else if(k == 2){
       cout << a[2] << " " << b[2];	
       return 0;
	}
	
	cout << dp_a(k) << " " << dp_b(k);
	return 0;

	
	
	
}
