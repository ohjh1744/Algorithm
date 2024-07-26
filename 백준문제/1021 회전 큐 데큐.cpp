#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 1 ;i <= n; i++){
		dq.push_back(i);
	}
	
	int ct =0;
	int idx = 0;
	
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		if(num == dq.front()){
			dq.pop_front();
			continue;
		}
		for(int i = 0; i < dq.size(); i++){
			if(dq[i] == num){
				idx = i+1;
			}
		}
		
		if( idx - 1 <= dq.size() - (idx -1) ){
    		while(num != dq.front()){
    			int t = dq.front();
    			dq.pop_front();
    			dq.push_back(t);
    			ct++;
			}
			dq.pop_front();
		}
		else{
			while(num != dq.front()){
				int m = dq.back();
				dq.pop_back();
				dq.push_front(m);
				ct++;
			}
			dq.pop_front();
		}
		
	}
	cout << ct << endl; 
	
}
