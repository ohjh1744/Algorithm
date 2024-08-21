#include <iostream>
#include <set>
using namespace std;

int n;
int sel[20];
int temp[4] = {1, 5, 10, 50};
set <int> st; // 정답개수 

void dfs(int item, int cnt)
{
	if(cnt == n){
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum = sum + sel[i];
		}
		st.insert(sum);
		return;
	}
	
	for(int i = item; i < 4; i++){
		sel[cnt] = temp[i];
		dfs(i, cnt+1);
	}
	
}

int main()
{
	cin >> n;
	dfs(0, 0);
		
	set <int> :: iterator iter;
	cout << st.size() << "\n";
	
}
