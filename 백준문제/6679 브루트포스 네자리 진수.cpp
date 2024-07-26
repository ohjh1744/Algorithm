#include <iostream>
using namespace std;

int digit(int n, int x) //x °¡ 10, 12, 16 
{
	int result = 0;
	while(n){
		result = result + (n % x);
		n = n/x;
	}
	return result;
}

int main()
{
	for(int i = 1000; i <= 9999; i++){
		if(digit(i,10) == digit(i,12) &&  digit(i, 12) == digit(i,16)){
			cout << i << endl;
		}
	}	
	
} 


