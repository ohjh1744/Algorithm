#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	string book[1001];
	
	for(int i = 0; i < n; i++){
	   cin >> book[i];
	}
	
	sort(book , book + n);
	
	int ct = 1;
	int ans_ct = 0;
	string ans;
	
	for(int i = 0 ; i < n; i++){
		if(book[i] == book[i+1]){
			ct++;
		}
		else{
			ct = 1;
		}
		
		if(ans_ct < ct){
			ans_ct = ct;
			ans = book[i];
		}
	}
	cout << ans << endl;
		
}
