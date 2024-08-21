#include <iostream>
#include <algorithm>
using namespace std;

unsigned int k, n, big ;
unsigned int list[10000];
unsigned int ans;

bool check(int length){
	int ct = 0;
	for(int i = 0; i <k; i++){
		ct = ct + (list[i] / length);
	}
	cout << ct << endl;
	if(ct >= n){
		return true;
	}
	else{
		return false;
	}
}

void bs()
{
	unsigned int left = 1;
	unsigned int right = big;
	unsigned int mid = 0;
	while(left <= right){
		mid = (left + right) / 2;
		cout << left << " " << right << " " << mid << endl;
		if(check(mid)){
			left = mid + 1;
			ans = mid;
		}
		else{
			right = mid - 1;
		}
	}
}
int main()
{
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> list[i];
		big =  max(big, list[i]);	
	}
	bs();
	cout << ans << '\n';
		
}
