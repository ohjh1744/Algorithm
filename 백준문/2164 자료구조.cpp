#include <iostream>
#include <queue>
using namespace std;

int n;
int main()
{
	queue<int> q;
	cin >> n;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	while(q.size() > 1){
		q.pop();
		int num = q.front();
		q.pop();
		q.push(num);
	}
	
	cout << q.front() << endl;	
}
