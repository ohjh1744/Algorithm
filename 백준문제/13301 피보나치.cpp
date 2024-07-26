#include<iostream>
using namespace std;

long long temp[81];

void fibonacci(int n){   \
	temp[1] = 1;
	temp[2] = 1;
	for(int i =3; i<=n; i++){ 
		temp[i] = temp[i-1] + temp[i-2];
	}
}

int main()
{
	int num;
	long long  result;
	cin >> num;
	if(num == 1){
		result = 4;
	}
	fibonacci(num);
	result =((temp[num] + temp[num-1]) + temp[num]) * 2;
	cout << result;
	
}

