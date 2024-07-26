#include <iostream>
#include <vector>
using namespace std;

int ct = 0;
int temp[3]; // 각자리수 비교 
int main()
{
	int n;
	cin >> n;
	if(n < 100){
		cout << n << endl;
	}
	else{
		
		for(int i = n; i >= 100; i--){
			temp[0] = (i % 10);
			temp[1] = (i / 10) % 10;
			temp[2] = (i / 100);
			if(temp[1] - temp[0] == temp[2] - temp[1]){
				ct++; 
			}
		}
		cout << 99 + ct << endl;
	}
}
