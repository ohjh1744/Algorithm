#include <iostream>
using namespace std;

int n, num1 , num2;

int main()
{
	cin >> n >> num1 >> num2;
	
	int round = 0;
	while(1){
		round++;
		num1 = (num1+1) / 2;
		num2 = (num2+1) / 2;
		
		if( num1 == num2){
			cout << round << endl;
			return 0;
		} 
	}
	cout << "-1" << endl;
	
}
