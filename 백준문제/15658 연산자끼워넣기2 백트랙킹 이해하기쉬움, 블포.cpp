#include <iostream>
#include <vector>
using namespace std;


//https://yabmoons.tistory.com/157 Âü°í 
int n;
int num[11];
int pp, mii, mull, divi;

int max_ans = -99999999999;
int min_ans =  99999999999;

void dfs(int p, int mi, int mu, int d, int sum, int ct)
{
	if(ct == n){
		if(sum > max_ans){
		  max_ans = sum;		
		}
		if(sum < min_ans){
	      min_ans = sum;	
		}
		return;
	}
	
	
	if(p < pp){
		dfs(p+1, mi , mu , d, sum + num[ct], ct+1);
	}
	if(mi < mii){
		dfs(p, mi+1 , mu , d, sum - num[ct], ct+1);
	}
	if(mu < mull){
		dfs(p, mi , mu+1 , d, sum * num[ct], ct+1);
	}
	if(d < divi){
		dfs(p, mi , mu , d+1, sum / num[ct], ct+1);
	}
	
	
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	cin >> pp >> mii >> mull >> divi;
	dfs(0, 0, 0, 0, num[0], 1);
	cout << max_ans << "\n";
	cout << min_ans << "\n";
}
