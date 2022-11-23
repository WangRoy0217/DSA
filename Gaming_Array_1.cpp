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
string gamingArray(vector<int> arr) {
	int reverseCount=0;
	int max=INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
    	if(max < arr[i])
    	{
    		max = arr[i];
    		reverseCount++;
    	}
    }
    if(reverseCount&1)
    	return "Bob";
    return "Andy";
}

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> v = {2,3,5,4,1};
	cout<<gamingArray(v)<<endl;
	
	return 0;
}