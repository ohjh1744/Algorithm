#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string temp[100001];

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector<string> temp;
    string answer = "";
    

    for (int i = 0; i < numbers.size(); i++) {
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for (int i = 0; i < temp.size(); i++) {
        if(i == 0){
            if(temp[i] == "0"){
                continue;
            }
        }
        answer += temp[i];
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}
