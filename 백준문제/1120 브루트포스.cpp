#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string A, B;
	cin >> A;
	cin >> B;
	
	int C = B.length() - A.length();
	int ans = 1000000;
	for(int i = 0; i < C+1; i++){ 
		int ct = 0;
		for(int j = 0; j < A.length(); j++){
			if(A[j] != B[i+j]){  
				ct++;
			}
		}
		ans = min( ans, ct);
	}
	
	cout << ans << endl;
}
