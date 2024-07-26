#include <iostream>
using namespace std;
//이해안되면 참고 
//https://boomrabbit.tistory.com/84
int t;
unsigned long long n;

void b_s(){
	unsigned long long left = 1;
	unsigned long long right = n;
	unsigned long long ans = 0;
	while(left <= right){    //예를들어 n= 9일때 mid(건너는 돌개수) : 5 -> 2 -> 3  ex)mid가 2일때 (최소간격 등차수열)1+ 2 or 1+ 8로 바꿀수있따 즉 꼭 n에 도착안하더라도 마지막 숫자를 바꾸면댐 
		unsigned long long mid = (left + right) / 2;
		unsigned long long cal = mid*(mid+1)/2;
		if(cal <= n){
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << ans << "\n";
}

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		b_s();
	}
	
}
