#include <iostream>
#include <string>
using namespace std;

// - 만났는지 체크. 
bool check = false;
 // -가 오면 그 뒤 숫자는 모두 다 빼주면 된다. 
int main()
{
	string n;
	string result;
	int result_2 = 0;
	cin >> n;
	for(int i = 0; i <= n.length(); i++){
		
		if(n[i] == '+' || n[i] == '-' || n[i] == '\0'){
			if(check){
			   result_2 = result_2 - stoi(result);
		    }
		    else{
			   result_2 = result_2 + stoi(result);
		    }
		    result = "";
		    //- 만났으면 그다음부턴 result값 다 빼주기 그전까진 더해주기. 
		    if(n[i] == '-'){
		       check = true;
	        }
		}
		// 숫자의 경우 계속 채워넣기. 
		else{
			result = result + n[i];
		}
		cout << result << " " << result_2 << endl; 
	}
	cout << result_2 << endl;	

}
