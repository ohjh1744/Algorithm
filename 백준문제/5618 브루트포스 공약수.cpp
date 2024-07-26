#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, c;
	
	cin >> n;
	
	if(n == 2){
		cin >> a >> b;
		for(int i = 1; i <= a && i <= b ; i++){
			if((a % i) == 0 && (b % i) ==0 ){
				cout << i << endl;
			}
		}
	}
	else{
		cin >> a >> b >> c;
		for(int i = 1; i <= a && i <= b && i <= c ; i++){
			if((a % i) == 0 && (b % i) == 0 && (c % i) == 0 ){
				cout << i << endl;
			}
		}
	}
	
	return 0;
	
	
	
	
}
