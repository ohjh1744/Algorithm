#include <iostream>
using namespace std;
//���ؾȵǸ� ���� 
//https://boomrabbit.tistory.com/84
int t;
unsigned long long n;

void b_s(){
	unsigned long long left = 1;
	unsigned long long right = n;
	unsigned long long ans = 0;
	while(left <= right){    //������� n= 9�϶� mid(�ǳʴ� ������) : 5 -> 2 -> 3  ex)mid�� 2�϶� (�ּҰ��� ��������)1+ 2 or 1+ 8�� �ٲܼ��ֵ� �� �� n�� �������ϴ��� ������ ���ڸ� �ٲٸ�� 
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
