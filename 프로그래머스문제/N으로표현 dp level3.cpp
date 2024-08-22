#include <string>
#include <vector>
#include <iostream>
#include<set>
using namespace std;

set<int> s[9]; // N i개로 만들 수 있는 값들 저장.
// 풀이 참고...  

int solution(int N, int number) {
    int answer = 0;
    
    int sum = 0;
    for(int i = 1; i <= 8; i++){
        sum = (sum*10) + N;
        s[i].insert(sum);
    }
    
    for(int i = 2; i <= 8; i++){
        for(int j = 1; j < i; j++){
            for(int a : s[j]){
                for(int b : s[i-j]){
                    s[i].insert(a +b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if(b != 0 ){
                        s[i].insert(a/ b);
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= 8; i++){
        for(int j : s[i]){
            if(j == number){
                answer = i;
                return answer;
            }
        }
    }
    
    return -1;
    
}
