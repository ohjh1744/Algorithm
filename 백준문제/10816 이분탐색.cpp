#include <iostream>
#include <algorithm>
using namespace std;

int temp[500000];
int fd[500000];


int main()
{
	int n;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> temp[i];
	}
	int m;
    cin >> m;
    for(int i=0; i < m; i++){
		cin >> fd[i];
	}
	
    sort(temp , temp + n);
    
    for(int i=0; i < m; i++){
		cout << upper_bound(temp, temp+n , fd[i]) - lower_bound(temp, temp+n , fd[i]) << " ";
	}
    
	
}


