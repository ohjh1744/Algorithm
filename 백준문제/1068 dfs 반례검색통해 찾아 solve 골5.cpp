#include <iostream>
#include <vector>
using namespace std;


vector<int> v[51];
int visited[51];
int n;
int rootNode;
int delNode;
int ans;

void dfs(int start){
	visited[start] = true;
	
	if(start == delNode){
		return;
	}
	for(int i = 0; i < v[start].size(); i++){
		int nn = v[start][i];
		if(visited[nn] == false && nn != delNode){
			dfs(nn);
		}
	}
}


int main(){
  
   cin >> n;
   
   for(int i = 0; i < n ; i++ ){
   	    int parent;
   	    cin >> parent;
   	    if(parent == -1){
   	    	rootNode = i;
   	    	continue;
		}
		v[parent].push_back(i);
   }
   
   cin >> delNode;
   
   //dfs	
   dfs(rootNode);
   
   //삭제할 노드가 루트노드라면 값은 0 
   if(delNode == rootNode){
   	  cout << 0 << endl;
   	  return 0;
   }

   // 방문한 노드 중에서 원래 자식이 없었다면 기존의 리프 노드
   // 방문한 노드 중에서 자식이 있었지만 그 자식이 삭제할노드로, 리프 노드가 된 노드가 존재. 
   for(int i = 0; i < n; i++){
   	 if(visited[i] == true){
   	 	if(v[i].empty()){
   	 		ans++;
		} 
   	 	else{
   	 		if(v[i].size() == 1 && v[i][0] == delNode){
   	 		  ans++;	
			}
		}
	 }
   } 
   
   cout << ans << endl;
   
}
