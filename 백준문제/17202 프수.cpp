#include <iostream>
using namespace std;

int main()
{
    int  n_2[17];
	int r = 16;
	
	for(int i = 1; i <= 16; i= i+2){
		 scanf("%1d", &n_2[i]);  
	}
	
	for(int i = 2; i <= 16; i= i+2){
		 scanf("%1d", &n_2[i]);
	}
	
	 for(int i=0; i<14; i++) {
        for(int j=1; j< r; j++) {
            n_2[j]=(n_2[j]+n_2[j+1])%10;
        }
        r--;
    }

	cout << n_2[1] << n_2[2];
	
}
