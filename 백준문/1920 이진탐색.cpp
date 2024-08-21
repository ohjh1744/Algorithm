#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];

void bs(int t, int arr[])
{
	int low =0;
	int high = n-1;
	while(low <= high){
	int mid = (low+high)/2;
	if(arr[mid] == t){
		cout << "1" << "\n";
		return ;
	}
	else if(arr[mid] > t){
		high= mid-1;
	}
	else if(arr[mid] < t){
		low= mid+1;
	}
		
	}
	cout << "0" << "\n";
	
}



int main()
{
	cin.tie(0);
	cout.tie(0);
   cin >> n;
   for(int i =0; i<n; i++){
   	int z;
	cin >> z;
   	a[i] = z;
   }
   
   sort(a, a+n);
   
   cin >> m;
   for(int i =0; i<m; i++){
   	 int t;
   	 cin >> t;
   	 bs(t, a);
   }
   
   
}
