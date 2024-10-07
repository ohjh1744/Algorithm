#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int visited[5];
vector <int> v;
int check[9999999]; //소수 여부 이미 체크한 숫자
int ans;

void IsPrime(int n){
    check[n] = true;
    // 0~1은소수x, 2~3은 소수.
    if(n <= 3){
        if(n >= 2){
            ans++;
            return;
        }
        else{
            return;
        }
    }    
    
    if (n % 2 == 0) return ;
    
    // 3부터 sqrt(n)까지 홀수로 나누어 확인
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0){
            return;
        }
    }
    ans++;
}

void dfs(int arr[], int cnt, int len){
    
    int sumResult = 0;
    for(int i = 0; i < v.size(); i++){
        sumResult = (sumResult*10) + v[i];
    }
    
    //여기서 이제 소수인지 확인
    if(check[sumResult] == false){
        IsPrime(sumResult);
    }
    
    if(cnt == len){
        return;
    }

    for(int i = 0; i < len; i++){
       if(visited[i]){
       	continue;
	   }
	   v.push_back(arr[i]);
	   visited[i]= true;  
	   dfs(arr, cnt+1, len);
	   visited[i] = false;
	   v.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;    
    int numbers2[numbers.length()];
    
    for(int i = 0; i < numbers.length(); i++){
        numbers2[i] = numbers[i] - '0';
    }
    
    dfs(numbers2, 0,  numbers.length());
    
    answer = ans;
    return answer;
}
