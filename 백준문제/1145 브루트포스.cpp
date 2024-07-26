#include <iostream>
using namespace std;


int main()
{
	int a,b,c,d,e;
	
	cin >> a >> b >> c >> d >> e;
	
	int ct;
	int num = 0;
	while(1){
        ct = 0;
		num++;
		if((num % a) == 0){
			ct++;
		}
	    if((num % b) == 0){
			ct++;
		}
		if((num % c) == 0){
			ct++;
		
		}
		if((num % d) == 0){
			ct++;
			
		}
		if((num % e) == 0){
			ct++;
			
		}
		if(ct >= 3){
			break;
		}
	 
	}
	cout << num << endl;
	
	

	
}
