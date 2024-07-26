#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f_r[4];
int n;
int num[12];
vector <int> v;

void dfs(int sum , int ct , int pl, int mi , int mul, int dv)  
{
	if(ct == n-1){ // 2
		v.push_back(sum);
	}
		
	if(pl > 0){
		dfs( sum + num[ct+1] , ct+1, pl - 1, mi, mul, dv);
	}
	if(mi > 0){
		dfs( sum - num[ct+1] , ct+1, pl, mi -1 , mul, dv);
	}
	if(mul > 0){
		dfs( sum * num[ct+1] , ct+1, pl, mi, mul-1, dv);
	}
	if(dv > 0){
		dfs( sum / num[ct+1] , ct+1, pl, mi, mul, dv-1);
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> num[i];
	}
	
	for(int i = 0; i < 4; i++){
		cin >> f_r[i];
	}
	
   dfs(num[0], 0, f_r[0], f_r[1], f_r[2], f_r[3]);

   sort(v.begin(), v.end());
   cout << v.back() << endl; 
   cout << v.front() << endl; 
	
} 


