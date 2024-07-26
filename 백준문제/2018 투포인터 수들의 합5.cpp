#include <iostream>
using namespace std;


int n;
int ans; // ¸î°¡Áö 
int main()
{
	cin >> n;
	
	int start = 1;
	int end = 1;
	int temp = 1;
	
	while(end <= n && start <= n){
		if(temp == n){
			ans++;
			end++;
			temp = temp + end;
			temp = temp - start;
			start++;
		}
		else if(temp < n){
			end++;
			temp = temp + end;
		}
		else if(temp > n){
			temp = temp - start;
			start++;
		}

	}
	cout << ans << endl;
}
