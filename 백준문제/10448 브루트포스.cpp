#include<iostream>
using namespace std;

int t[45];


bool tri(int num)
{
	for(int i = 1; i < 45; i++){
	  for(int j = 1; j< 45; j++){
			for(int z = 1; z< 45; z++){
				int ans = t[i] + t[j] + t[z];
				if(ans == num){
					return 1;
				}
			}
	}	
	}
	
	return 0;
	
}




int main(){
	
	for(int i = 1; i < 45; i++){
		t[i] = i + t[i-1];
	}
	
	int n ;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		cout << tri(num) << endl;
	} 
	
	
	
}
