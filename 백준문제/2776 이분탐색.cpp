#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;
int bsh(int key){
	int right = v1.size() - 1;
	int left = 0;
	while(left <= right){
		int mid = (left + right) / 2;
		if(v1[mid] == key){
			return 1;
		}
		if(v1[mid] < key){
			left = mid + 1;
		}
		if(v1[mid] > key){
			right = mid - 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t, n, m;
	cin >> t;
	while(t--){

		cin >> n;

		for(int i  = 0; i < n; i++){
			int num;
			cin >> num;
			v1.push_back(num);
		}
	
		cin >> m;
		sort(v1.begin(), v1.end());
		for(int i  = 0; i < m; i++){
			int num;
			cin >> num;
			cout << bsh(num) << "\n";
		}
		v1.clear();
	
	}
	
	
}
