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
   
   //������ ��尡 ��Ʈ����� ���� 0 
   if(delNode == rootNode){
   	  cout << 0 << endl;
   	  return 0;
   }

   // �湮�� ��� �߿��� ���� �ڽ��� �����ٸ� ������ ���� ���
   // �湮�� ��� �߿��� �ڽ��� �־����� �� �ڽ��� �����ҳ���, ���� ��尡 �� ��尡 ����. 
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
