#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int temp[100000];
	
	for(int i = 0; i < n; i++){
		cin >> temp[i];	
	}
	
	sort(temp, temp+ n, greater<int>()); //내림차순 
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int result = temp[i] * (i+1);
		ans = max(ans, result);
	}
	
	cout << ans << endl;
}
