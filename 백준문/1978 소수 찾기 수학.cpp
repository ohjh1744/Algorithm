#include<iostream>
using namespace std;


int n;
int ans;
bool b = false;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(num == 1){
			continue;
		} 
		b = false;
		for(int j = 2; j < num; j++){
			if(num % j == 0){
				b = true;
				break;
			}
		}
		if(!b){
			ans++;
		}		
	}
	
	cout << ans << "\n";
}



