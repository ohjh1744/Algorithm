#include<iostream>
using namespace std;
int arr[3] = { 1,2,3 };
int combi[3];
void dfs(int index,int cnt)
{
    if (cnt == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << combi[i] << " ";
        }cout << endl;
        return;
    }
    for (int i = index; i < 3; i++)
    {
        combi[cnt] = arr[i];
        dfs(index, cnt + 1); // �ε������ؾ� ó������ ������ 
    }
}


//�Ǵ� �������� visited�����
void dfs(int cnt)
{
	if(cnt == 3){
		for(int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i = 0; i < n; i++){
		v.push_back(arr[i]);
		dfs(cnt+1);
		v.pop_back();

	}
}
 
int main()
{
    dfs(0,0);
}
