#include <iostream>
#include <vector>
using namespace std;

int visited[5];
vector <int> v;



void dfs(int cnt){
    if(cnt == 5){
        for(int i = 0; i < v.size(); i++){
        	cout << v[i] << " ";
		}
		cout << endl;
        return;
    }

    for(int i = 0; i < 5; i++){
       if(visited[i]){
       	continue;
	   }
	   v.push_back(i);
	   visited[i]= true;   //visitüũ ���ϸ� �ߺ����� �ϸ� ���� 
	   dfs(cnt+1);
	   visited[i] = false;
	   v.pop_back();
    }
}

int main(void){
    dfs(0);
}
