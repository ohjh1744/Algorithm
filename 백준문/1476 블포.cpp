#include <iostream>
using namespace std;

int e , s, m;

int main()
{
	cin >> e >> s >> m;
	
	int i = 0;
	int e_2 = 0, s_2 = 0, m_2 = 0;
	while(true)
	{
	   i++;
	   e_2++;
	   s_2++;
	   m_2++;
	   if(e_2 > 15){
	   	e_2 = 1;
	   }
	   if(s_2 > 28){
	   	s_2 = 1;
	   }
	   if(m_2 > 19){
	   	m_2 = 1;
	   }
	   if(e == e_2 && s == s_2 && m == m_2){
	   	break;
	   }
		
	}
	cout << i << endl;
	
}
