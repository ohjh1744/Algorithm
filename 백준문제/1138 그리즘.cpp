#include <iostream>
using namespace std;

int main()
{
	
	int n, h[11]; // 키저장 
	cin >> n;
	
	int arr[n+1]; // 1자로 쭉 오름차순 
	
	for(int i = 1; i <= n; i++){
		arr[i] = i;
		cin >> h[i];
	}
	
	
	for(int i = n; i > 0 ; i--){
		if(h[i] > 0){
			for(int j = i; j < i+ h[i] ; j++){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
	
	for(int z = 1; z <= n; z++){
			cout << arr[z] << " ";
	}

	
	
}
