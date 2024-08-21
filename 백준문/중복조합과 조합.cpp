#include <iostream>
using namespace std;

int num[3] = {1,2,3};
int select[2];

void dfs(int index, int cnt){
    if(cnt == 2){
        for(int i = 0; i < 2; i++)
            printf("%d ", select[i]);
        printf("\n");
        return;
    }

    for(int i = index; i < 3; i++){
        select[cnt] = num[i]; 
        dfs(i, cnt+1); // i면 중복조합, i+1이면 조합 
    }
}

int main(void){
    dfs(0,0);
}
