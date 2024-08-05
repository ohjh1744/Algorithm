#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visited[51];
int ans = 99999;
int mov = 0;

void dfs(string start , int len, string target, vector<string> words)
{
                 		            
	if(start == target){
		if(ans > mov){
			ans = mov;
		}
	}
	for(int i = 0; i < words.size(); i++){
		int ischange = 0;
		for(int j = len-1; j >= 0; j--){
			char c1 = start[j];
			char c2 = words[i][j];
			if(c1 == c2){
				ischange++;
			}
		}
		
		if(ischange == len-1 && !visited[i]){
			visited[i] = true;
			mov++;
			dfs(words[i], len, target, words);
			mov--;
			visited[i] = false;			
		}
	}
	
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, words[0].length(), target, words);
    answer = ans;
    if(answer == 99999){
        return 0;
    }
    return answer;
}
