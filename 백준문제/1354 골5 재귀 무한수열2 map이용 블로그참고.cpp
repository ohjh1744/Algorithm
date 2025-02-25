#include <iostream>
#include <vector>
using namespace std;

int n;
int graph[6][6];
int maxValue = 0;
int minValue = 9999999;

int dx[4] = {1,  0 };
int dy[4] = {0,  1};

vector<int> v; 

void dfs(int y, int x){
	
   if(y == n-1 && x == n-1){
   	 int result = v[0];
   	 for(int i = 1; i < v.size(); i = i + 2){
   	 	if(v[i] == -1){
   	 	  result += v[i+1];	
		}
		else if(v[i] == -2){
   	 	  result -= v[i+1];	
		}
		else if(v[i] == -3){
   	 	  result *= v[i+1];	
		}
	 }
	 if(result > maxValue){
	 	maxValue = result;
	 }
	 
	 if(result < minValue){
	 	minValue = result;
	 }
	 return;
   }
   
   for(int i = 0; i < 2; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(nx < 0 || ny < 0 || nx >= n || ny >= n ){
         continue;
      }
      
      v.push_back(graph[ny][nx]);
      dfs(ny, nx);
      v.pop_back();
      
   }
}

int main(){
   cin >> n;
   
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         char c;
         cin >> c;
         if(c == '+'){
            graph[i][j] = -1;
         }
         else if(c == '-'){
            graph[i][j] = -2;
         }
         else if(c == '*'){
            graph[i][j] = -3;
         }
         else{
            graph[i][j] = c - '0';
         }
      }
   }
   
   v.push_back(graph[0][0]);
   
   dfs(0, 0);
   
   cout << maxValue << " ";
   
   cout << minValue<< "\n";
   
}
