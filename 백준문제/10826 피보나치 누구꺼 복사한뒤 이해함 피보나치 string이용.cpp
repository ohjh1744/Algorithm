#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
string a, b, tmp, fibo[10001];
vector<int> ans, num1, num2;

string big_number_sum(string s1, string s2)
{
	string s;

	// 더 긴 수를 s1으로 저장하기
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// num1, num2 배열을 만드는 과정
	num1.push_back(0);
	num2.push_back(0);

	for (int i = 0; i < s1.size() - s2.size(); i++)
		num2.push_back(0);

	for (int i = 0; i < s1.size(); i++)
		num1.push_back(s1[i] - '0');

	for (int i = 0; i < s2.size(); i++)
		num2.push_back(s2[i] - '0');

	// num배열들의 끝부분부터 덧셈을 하면서 ans벡터에 값 저장
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}

	// 맨 앞자리수 출력
	if (num1.front() != 0) s.push_back('1');

	// ans벡터 거꾸로 출력
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		s.push_back(ans[i]+48);
	}

	num1.clear();
	num2.clear();
	ans.clear();

	return s;
}

int main()
{
	cin >> N;

	fibo[0] = '0';
	fibo[1] = '1';

	for (int i = 2; i <= N; i++)
	{
		fibo[i] = big_number_sum(fibo[i - 1], fibo[i - 2]);
	}
	
	cout << fibo[N];

}
