#include <iostream>
using namespace std;

int n;
int main()
{
	cin >> n;
	int a = 100;
	int b = 100; //Ã¢¿µ »ó´ö 
	
	for(int i = 0; i < n; i++){
		int num1, num2;
		cin >> num1 >> num2;
		if(num1 == num2){
			continue;
		}
		else{
			if(num1 > num2){
				b = b - num1;
			}
			else if(num1 < num2){
				a = a - num2;
			}
		}
	}
	
	cout << a << "\n" << b;
}
