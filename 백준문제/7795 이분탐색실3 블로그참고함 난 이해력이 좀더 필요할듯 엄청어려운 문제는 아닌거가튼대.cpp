#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m;
int ct;

int b_search(int a, int b[]) // b배열중에서 a[i]값보다 작은데 그중에서 가장 큰값의 index + 1이 개수 
{
	int start = 0;
	int end = m-1;
	int mid;
	int res = -1;
	while(start <= end){
		mid = (start + end) / 2;
		if(a > b[mid]){
			res = mid; //인덱스 저장 
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return res; //최종  
}


int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int A[20000];
		int B[20000];
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		for(int i = 0; i < m; i++){
			cin >> B[i];
		}
		ct = 0;
		sort(A, A+n);
		sort(B, B+m);
		
		for(int i = 0; i < n; i++){
			int c = A[i];
			ct += b_search(c, B) + 1;			
		}
		cout << ct << "\n";
			
	}
	
	
}
