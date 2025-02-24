#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans= 99999999;
vector < pair < int, int > > v;

// https://rjsdh15963.tistory.com/56 ��α� ����. 

int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int t, s;
		cin >> t >> s;
		v.push_back({s, t});
	}
	
	//ó���ؾ��� �ð� s�� �������� �������� ���� 
	sort(v.begin(), v.end());
	
	int currentTime = 0;
	
	for(int i = 0; i < v.size(); i++){
		int s = v[i].first;
		int t = v[i].second;
		
		currentTime += t;
		// ���� �ð� 0���� t�� ���� �����ְ�, �� ���� s���� ��.
		// �� �������� ���� �� ���̰� ���� ���� �ִ��� �ʰ� ������ �� �ִ� �ð�.
		// ���� ������ ���� ������ ���� �ð��� ������. 
		ans = min(ans, s - currentTime);
		
		if(ans < 0){
			ans = -1;
			break;
		}
	}
	
	cout << ans << "\n";
	
}
