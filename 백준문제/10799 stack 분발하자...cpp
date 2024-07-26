#include <iostream>
#include <stack>
using namespace std;

stack <char> st; 
int result = 0;

int main()
{
   string input;
   cin >> input;

   
   for(int i =0; i < input.size(); i++){
   	  if(input[i] == '('){
   	  	st.push(input[i]);
	  }
	  else if(input[i] == ')'){
	  	if(input[i-1] == '('){
	  		st.pop();
	  	    result = result + st.size();
		}
		else if(input[i-1] == ')'){
			result = result + 1;
			st.pop();
		}
	  }
   }
   
   cout << result << endl;
   
   
   
   
}
