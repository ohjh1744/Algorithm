#include <iostream>
#include <string>
using namespace std;

// - �������� üũ. 
bool check = false;
 // -�� ���� �� �� ���ڴ� ��� �� ���ָ� �ȴ�. 
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
		    //- �������� �״������� result�� �� ���ֱ� �������� �����ֱ�. 
		    if(n[i] == '-'){
		       check = true;
	        }
		}
		// ������ ��� ��� ä���ֱ�. 
		else{
			result = result + n[i];
		}
		cout << result << " " << result_2 << endl; 
	}
	cout << result_2 << endl;	

}
