#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans= 99999999;
vector < pair < int, int > > v;

// https://rjsdh15963.tistory.com/56 블로그 참고. 

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
	
	//처리해야할 시간 s를 기준으로 오름차순 정렬 
	sort(v.begin(), v.end());
	
	int currentTime = 0;
	
	for(int i = 0; i < v.size(); i++){
		int s = v[i].first;
		int t = v[i].second;
		
		currentTime += t;
		// 현재 시간 0에서 t를 점차 더해주고, 그 값을 s값과 비교.
		// 각 과정에서 가장 그 차이가 작은 값이 최대한 늦게 시작할 수 있는 시간.
		// 만약 음수의 값이 나오면 일을 시간내 못끝냄. 
		ans = min(ans, s - currentTime);
		
		if(ans < 0){
			ans = -1;
			break;
		}
	}
	
	cout << ans << "\n";
	
}
