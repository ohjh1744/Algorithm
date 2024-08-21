#include<iostream>
using namespace std;

int f_1c, f_2c;
 
int fib(int n){       //Àç±Í 
	f_1c ++;
	if(n==1 || n==2){
		return 1;
	}
	else{
		return fib(n-1) + fib(n-2);
	}
	return f_1c;
}

int temp[41]; 

void fibonacci(int n){   // µ¿Àû
	temp[1] = 1;
	temp[2] = 1;
	for(int i =3; i<=n; i++){
		f_2c++; 
		temp[i] = temp[i-1] + temp[i-2];
	}
	cout <<  f_2c << endl;
}


int main()
{
   int num;
   cin >> num;
   cout << fib(num) << endl;
   fibonacci(num);
}
