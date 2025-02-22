#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<char>v;
char temp[5] = {'A', 'E', 'I', 'O', 'U'};
int num = -1;
bool isFind; 
int findAnswer;

void dfs(int cnt, string word ){
	
	num++;
    string subCurWord(v.begin(), v.begin() + cnt);
    cout << "현재문자 출력: " << num << ": " << subCurWord << endl;
    if(word == subCurWord){
    	cout << "찾음: "<<  num << endl;
        findAnswer = num;
    	isFind = true;
    	return;
	}
	
    if(cnt == 5){
        return;
    }

    for(int i = 0; i < 5; i++){
       if(isFind == true){
    		break;
	   }
	   v.push_back(temp[i]);
	   dfs(cnt+1, word);
	   v.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs(0, word);
    
    answer = findAnswer;
    
    return answer;
}
