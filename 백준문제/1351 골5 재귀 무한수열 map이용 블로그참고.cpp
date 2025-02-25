#include <iostream>
#include <unordered_map>
using namespace std;


// longlong�� �������� n�� pq ���� 10��9���̻��̱⶧����
//longlong�迭�� �����ʰ� map�� �� ������ N�� 10�� 12������ ũ�Ⱑ �ʹ�ũ�⶧���� �迭�ڷḦ ��� ����. 
//map�� �޸������̼��� ���. 
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
