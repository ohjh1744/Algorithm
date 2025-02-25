#include <iostream>
#include <unordered_map>
using namespace std;


// longlong을 쓴이유는 n과 pq 각각 10의9승이상이기때문에
//longlong배열을 쓰지않고 map을 쓴 이유는 N이 10의 12승으로 크기가 너무크기때문에 배열자료를 사용 못함. 
//map과 메모이제이션을 사용. 
unordered_map<long long, long long> hashMap;

long long n;
long long p;
long long q;

long long Sol(long long s){
	if(hashMap.find(s) != hashMap.end()){
		return hashMap[s];
	}
	else{
		return hashMap[s]  = Sol(s/p) + Sol(s/q);
	}
	
}

int main(){
	
	cin >> n >> p >> q;
	
	if(n == 0){
		cout << 1 << "\n";
		return 0 ; 
	}
	
	long long ans;
	
	hashMap[0] = 1;
	
	ans = Sol(n/p) + Sol(n/q);
	
	cout << ans << "\n";
}
