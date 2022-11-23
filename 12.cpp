#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;



void print(vector<char> v)
{
	for(auto& i:v)
	{
		cout<<i<<",";
	}
}
void getchar(vector<char> &arr, int n)
{

}
string intToRoman(int num)
{
	string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	string huns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	string thus[]={"","M","MM","MMM"};
	return thus[num/1000] + huns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}
/*
//wrong

string IntToRoman(int num)
{
	vector<char> arr;
	map<int,char> m = { {1,'I'},
						{5,'V'},
						{10,'X'},
						{50,'L'},
						{100,'C'},
						{500,'D'},
						{1000,'M'} };
	int n=0,count=0,sum=0;
	while(num!=0)
	{
		sum = sum*10 + num%10;
		n = (int) (sum / pow(10,count)) * pow(10,count);
		cout<<n<<"->";
		cout<<num<<","<<sum<<endl;
		while(n!=0)
		{
			for(auto iter=m.begin();iter!=m.end();iter++)
			{
				if(n <= 4*iter->first)
				{
					arr.push_back(iter->second);
					n = abs(n - iter->first);
					break;
				}
			}
		}
		num/=10;
		count++;
	}
	print(arr);
	return "";
}
*/

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<intToRoman(1994)<<endl;
	
	return 0;
}