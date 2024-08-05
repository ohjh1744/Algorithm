#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int result, int i, vector<int> numbers, int target){
    if(i == numbers.size()){
        if(result == target){
            answer++;
        }
        return;
    }
    
    dfs(result + numbers[i], i+1, numbers, target);
    dfs(result - numbers[i], i+1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    return answer;
}
