#include <iostream>
using namespace std;

int main()
{
	int temp[9];
	int n;
	int sum;
	
	for(int i=0; i<9; i++){
		cin >> n; 
		temp[i] = n;
	}
	
	for(int i=0; i<9; i++){
		sum += temp[i];
	}
	
	for(int i=0; i<8; i++){
		for(int j= i+1; j< 9; j++){
			int num = sum - (temp[i] + temp[j]);
			if(num == 100){
				for(int k =0; k <9; k++){
				   if(k== i || k==j)continue;
				   cout << temp[k] << endl;	
				}
			}
		}
	}
	

	
   
}
