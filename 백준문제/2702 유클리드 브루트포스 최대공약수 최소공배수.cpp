#include <iostream>
using namespace std;

//최대공약수 
int gcd(int a, int b){
	
	int r = b % a;
	while(r){
		b= a;
		a= r;
		r = b % a;
	}
	return a;
	 
} 





int main()
{
	int n, a, b;
	cin >> n;
	
	int ct;
	
	for(int i =0; i<n ; i++){
	cin >> a >> b;
	cout << (a*b)/gcd(a,b) << " " << gcd(a,b) << endl;
	
	}
	
	
	
	
	
	
}
