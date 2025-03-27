#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector< pair < int, int > > v; 
int n; // Äù½ºÆ® ¼ö 
int visited[11];
vector < int> quest; 
int ans;

void dfs(int cnt, int level){
   
   if(cnt > ans){
      ans = cnt;
      for(int i = 0; i < quest.size(); i++){
         cout << quest[i] << " ";
      }
      cout << endl;
   }
   
   for(int i = 0; i < v.size(); i++){
      if(visited[i] == false){
         if(v[i].first <= level){
            visited[i] = true;
            quest.push_back(i);
            dfs(cnt+1, level + v[i].second);
            quest.pop_back();
            visited[i] = false;
         }
      }
   }
}

int main(){
   cin >> n;
   int currentLevel = 0;
   
   for(int i = 0; i < n; i++){
      int need, get;
      cin >> need >> get;
      v.push_back({need, get});
      
      if(need == 0){
         visited[i] = true;
         currentLevel = get;
      }
   }
   
   dfs(1, currentLevel);
   
   cout << ans;
   
}
