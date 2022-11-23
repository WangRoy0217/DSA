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
string balancedSums(vector<int> arr) {
	int sum=0;
	for(auto i:arr)
		sum+=i;
	int add=0;
	for(int i=0;i<arr.size();i++)
	{
		if(sum-add == arr[i])
		{
			cout<<i<<endl;
			return "YES";
		}
		add+=arr[i];
		sum-=arr[i];
	}
	return "NO";

}

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> v = {1,4,8,2,3};
	cout<<balancedSums(v)<<endl;
	
	return 0;
}