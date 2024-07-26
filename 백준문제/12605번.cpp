#include<iostream>
#include<string>
#include<list>
#include<sstream>
using namespace std;

int main()
{
  int num;
  cin >> num;
  cin.ignore();
  
  string *st = new string[5];
    
  
  for(int i =0; i < num ; i++){
  	getline(cin, st[i]);
  }
  
   
  for(int i =0; i < num ; i++){
   istringstream ss(st[i]); //공백확인
    
  string sb;
  list<string> x;
  list<string>::iterator it;
  
  while(getline(ss, sb,' ')){
  	x.push_front(sb);
  }
  
  cout << "Case #" << i+1 << ": ";
  
  for(it = x.begin(); it != x.end(); it++){
  	cout <<*it + " " ;
  }
  cout << endl;


}
  
  
  


  
  
  
	
}
