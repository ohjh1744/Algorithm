#include <iostream>
using namespace std;

int n, k;
char temp[20000];
bool eat[20000]; // ÇÜ¹ö°Å Ã¼Å© 
int ans;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		 cin >> temp[i];
	}
	
	for(int i = 0; i < n; i++){
		if(temp[i] == 'P'){
			for(int j = i - k; j <= i + k; j++){
				if(j < 0 || j >=n ){
					continue;
				}
				if(temp[j] == 'H' && eat[j] == false){
					eat[j] = true;
					ans++;
					break;
				}
			}
		}
	}
	
	cout << ans << "\n";
	
}
