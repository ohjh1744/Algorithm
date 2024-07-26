#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque <int> dq;
int paper[1001];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		dq.push_back(i);
		cin >> paper[i];
	}
	
	while(!dq.empty()){
		int p = dq.front();
		cout << p << " ";
		dq.pop_front();
		if(paper[p] > 0){
			for(int i = 0; i < abs(paper[p]) - 1; i++){
				int fp = dq.front();
			    dq.push_back(fp);
			    dq.pop_front();			
			}
		}
		else if(paper[p] < 0){
			for(int i = 0; i < abs(paper[p]); i++){
				int fp = dq.back();
			    dq.push_front(fp);
			    dq.pop_back();			
			}
		}
		
	}
	
	
	
}
