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

bool isPalindrome(int x) 
{
	if(x<0 || (x!=0 && x%10==0))
		return false;
	int n=0;
	while(x>n)
	{
		n = n*10 + x%10;
		x/=10;
	}
	return n == x || n/10 == x;

}
int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<isPalindrome(121)<<endl;
	
	return 0;
}