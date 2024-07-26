#include <iostream>
#include <vector>
using namespace std;

int main()
{

	string A, B;
	cin >> A >> B;
	
	int stroke[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };


	
	vector<int> couple;


        for (int i = 0; i < A.size(); i++)

        {

                 couple.push_back(stroke[A[i] - 'A']);

                 couple.push_back(stroke[B[i] - 'A']);

        }
     
     
	
	 while(1){
	 	vector<int> temp;
     	for(int i = 0; i<couple.size()-1; i++){
     		temp.push_back((couple[i] + couple[i+1]) % 10);
		 }
		 couple = temp;
		 
		 if(couple.size() == 2){
		 	break;
		 }
	 }
	 
	 cout << couple[0] << couple[1] << endl;
      return 0;

}
