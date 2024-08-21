#include <iostream>
#include <algorithm>
using namespace std;
//https://lipcoder.tistory.com/94
int n, m;
int main()
{
	cin >> n >> m;
	if(n == 1){
		cout << "1" << endl;
	}
	else if(n == 2){
		cout << min(((m+1) / 2), 4) << endl;
	}
	else if(m < 7){
		cout << min(m, 4) << endl;
	}
	else{ // 4번이상 옮길때 
		cout << 5+m-7 << endl;
	}
	
}
