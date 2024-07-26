#include <iostream>
using namespace std;




int main()
{
	bool b = true;
    int n;
	cin >> n;
	
	int temp =0;
	
		for(int i = 1; i< n; i++){
	     int s = i;
	     int t = i;
	     
	     
	     while(t){
	     	s = s + t%10;
	     	t = t/10;
		 }
	     
	     
	     
		 if(s == n){
		 	temp = i;
		 	cout << temp;
		 	return 0;
		 }
		 		 
	   
	    }
		
	cout << 0;
		
}
