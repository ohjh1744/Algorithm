#include <iostream>
#include <vector>
using namespace std;


long long temp[91];


int main()
{
	int n;
	cin >> n;
	
	temp[0] = 0;
	temp[1] = 1;
	for(int i = 2; i <= n; i++){
		temp[i] = temp[i-2] + temp[i-1];
	}
	cout << temp[n];
}
