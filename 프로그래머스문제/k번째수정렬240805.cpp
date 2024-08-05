#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector <int> DoSort(vector<int> array, vector<vector<int>> commands ){
    
    vector<int> ans;
    
    for(int index = 0; index < commands.size(); index++){
    	int i = commands[index][0];
    	int j = commands[index][1];
    	int k = commands[index][2];
    	
    	vector <int> temp;
    	
    	for(int index = i-1; index <= j-1; index++){	
			temp.push_back(array[index]);
		}
		
		sort(temp.begin(), temp.end());
		
		ans.push_back(temp[k-1]);
	}
    
    for(int i = 0; i < ans.size(); i++){
    	cout << ans[i] << endl;
	}

    return ans;
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    answer = DoSort(array, commands);
    return answer;
}
