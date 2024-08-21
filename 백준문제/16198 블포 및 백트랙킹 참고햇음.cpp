#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n;
int ans;
vector<int> v; // 숫자저장 


int result;

void dfs()
{
	if(v.size() == 2){
		if(ans < result){
			ans = result;
			return;
		}
	}
	for(int i = 1; i < v.size()-1; i++){
	  int tmp = v[i];
	  cout << tmp << endl;
	  result = result + v[i-1] * v[i+1];
	  v.erase(v.begin()+ i);
	  dfs();
	  v.insert(v.begin()+ i, tmp);
	  result = result - v[i-1] * v[i+1];		
	}
}



int main()
{

	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	dfs();
    cout << ans << endl;

}
