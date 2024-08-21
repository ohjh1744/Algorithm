#include <iostream>
using namespace std;

int num[3] = {1,2,3};
int select[3];

void dfs(int index, int cnt){
    if(cnt == 3){
        for(int i = 0; i < 3; i++)
            printf("%d ", select[i]);
        printf("\n");
        return;
    }

    for(int i = index; i < 3; i++){
        select[cnt] = num[i]; //cnt = 1 index = 1  
        dfs(i, cnt+1);   // index = 1 cnt = 2  
    }
}

int main(void){
    dfs(0,0);
}
