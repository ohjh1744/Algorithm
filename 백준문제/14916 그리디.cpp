#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int ct = -1;
	
	int m = n / 5; 
	int r = n % 5; 
	if(r % 2 != 0){
		while(m){
			m--;   
			r = n - (m*5); 
			if(r % 2 == 0){
				ct = m + r/2;
				break;
			}
		} 		
	}
	else{
		ct = m + r/2;
	}
	
	cout << ct << endl;
	
	
}
