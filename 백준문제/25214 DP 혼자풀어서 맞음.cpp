#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[200001];
int temp[200001];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
  
    int small = 0;
    dp[0] = 0;
  
    for (int i = 1; i < n; i++) {
        //���� ���� �ε����� �� �� �迭�߿��� ���� ���������� �۴ٸ� 
  	    //�� �迭�� ���� �ִ밪�� ���� �ε����� ������ �迭�� ���� �ִ밪�� ����. 
        if (temp[small] > temp[i]) {
            small = i;
            dp[i] = dp[i-1];
        }
        // �ƴ϶�� ���� dp���� ���簪���� ������������ ���Ͱ� ���ؼ� �ִ밪 ���ϱ�. 
        else {
            dp[i] = max(dp[i-1], temp[i] - temp[small]);
        }
    }
  
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}
