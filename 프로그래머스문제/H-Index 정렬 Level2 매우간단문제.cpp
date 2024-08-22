#include <string>
#include <vector>

using namespace std;
int h = 0;
int maxh = 0;
int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = 10000; i  >= 0; i--){
        h = 0;
        for(int j = 0; j < citations.size(); j++){
            if(citations[j] >= i){
                h++;
            }
        }
        if(h >= i){
            maxh = i;
            break;
        }
    }
    
    answer = maxh;
    return answer;
}
