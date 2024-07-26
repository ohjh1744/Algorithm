#include <iostream>
using namespace std;

int main()
{
	
	cin.tie(0);
	cout.tie(0);
	long long s ;
	cin >> s ;
	
	int ct = 1;
	long long max = 0;
	long long i = 1;
	
	while(1){
		max = max + i;
		if(max > s){
			cout << ct-1 << endl;
			break;
		}  
		ct++;
		i++;
	}
	
	
}
