#include <iostream>
using namespace std;

int temp[1001];

int main()
{
	int n;
	cin >> n;
	
	temp[1] = 1;
	temp[2] = 2;
	if(n >= 3){
		for(int i = 3; i <= n; i++){
			temp[i] = (temp[i-1] + temp[i-2]) % 10007 ;
		} 
	}
	
	cout << temp[n]  << endl;
	
	
}
