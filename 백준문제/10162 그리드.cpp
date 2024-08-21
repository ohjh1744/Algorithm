#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	int a = 300 , b = 60 , c = 10;
	int a_c = 0 , b_c = 0, c_c = 0;
	
	int t;
	cin >> t;
	
	if(t % 10 != 0){
		cout << "-1" << endl;
	}
	
	else{
		a_c = t / a;
		t = t % a;
		b_c = t / b;
		t = t % b;
		c_c = t / c;
		cout << a_c << " " << b_c << " " << c_c << endl;
	}
	
	
}
