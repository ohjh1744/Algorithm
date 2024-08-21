#include <iostream>
using namespace std;

int n, m;
int arr[10000];

int main()
{
	cin >> n >> m;
	for(int i = 0; i< n; i++){
		cin >> arr[i];
	}
	
	int start = 0;
	int end = 0;
	int m_s = arr[0];
	int ct= 0;
	
	while(end < n && start <n){
		if(m_s < m){
			end++;
			m_s = m_s + arr[end];
		}
		else if(m_s >m){
			m_s = m_s - arr[start];
			start++;
		}
		else if(m_s == m){
			ct++;
			end++;
			m_s = m_s + arr[end];
			m_s = m_s - arr[start];
			start++;
		}
	
	}
	
	cout << ct << endl;
}
