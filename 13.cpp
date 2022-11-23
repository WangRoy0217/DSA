#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

void print(vector<vector<int>> v)
{
	for(auto& i:v)
	{
		for(auto& j:i)
			cout<<j<<",";
		cout<<endl;
	}
}
int romanToInt(string s)
{
	unordered_map<char,int> m = { {'I',1},
								  {'V',5},
								  {'X',10},
								  {'L',50},
								  {'C',100},
								  {'D',500},
								  {'M',1000} };
	int sum = m[s.back()];
	for(int i=s.size()-2;i>=0;i--)
	{
		if(m[s[i]] >= m[s[i+1]])
			sum+=m[s[i]];
		else
		{
			sum-=m[s[i]];
		}
	}
	return sum;
}
/*
int romanToInt(string s)
{
	int sum = 0,pre=INT_MIN;
	for(int i=s.size()-1;i>=0;i--)
	{
		int n;
		switch(s[i])
		{
			case 'I':
				n=1;
				break;
			case 'V':
				n=5;
				break;
			case 'X':
				n=10;
				break;
			case 'L':
				n=50;
				break;
			case 'C':
				n=100;
				break;
			case 'D':
				n=500;
				break;
			case 'M':
				n=1000;
				break;

		}
		if(n>=pre)
		{
			sum+=n;
			pre=n;
		}
		else
		{
			sum-=n;
		}
	}
	return sum;
}
*/
int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<romanToInt("MCMXCIV")<<endl;
	
	return 0;
}