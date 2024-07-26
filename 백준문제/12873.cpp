#include <iostream>
#include <queue> 
using namespace std;


int main()
{
	long long n;
	cin >> n;
	
	queue<long long> v;
	
	for(int i= 1 ; i <= n; i++){
		v.push(i);
	}
	
	long long t = 1;
	while(v.size() != 1)
	{
		long long  t_3 = t* t*t;
		long long ans = t_3 % v.size();
		if(ans ==0){
			ans = v.size();
		}
	   for(int i =0; i < ans-1 ; i++){
	   	long long stack = v.front();
	   	v.pop();
	   	v.push(stack);
	   }
	   t++;
	   v.pop();
	}
	cout << v.front();	
	
	
	
	

	
	
}
