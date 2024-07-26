#include <iostream>
#include <algorithm>
using namespace std;

int n;
int temp[51]; // 1~ 50
int big = 0; // 제일 많이받은후보의 득표수 
int num = 0; // 며번쨰후보가큰지
int ans = 0; 
bool same = false;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	while(1){
		same = false;
		big = 0;
		num = 0;
		for(int i = 1; i <= n; i++){
			if(big < temp[i]){
				big = temp[i];
				num = i;
			} 
			if(i == 1){
				continue;
			}
			if(temp[1] == temp[i]){
				same = true;
			}
		}
		if(big == temp[1]){
			if(same == true){
				cout << ans + 1 << "\n";
				return 0;
			}
			else if(same == false){
				break;
			}
		}
		ans++;
		temp[num] --;
		temp[1]++;			
    }

    cout << ans << "\n";
}
