#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	int temp[100000];
	int t_c = 0;
	
	for(int i = 1 ; i<= n; i++){
		int z = n % i; 
		if(z ==0){
			temp[t_c] = i;
			t_c++;
		}
	}
	
	cout << temp[k-1];
}
