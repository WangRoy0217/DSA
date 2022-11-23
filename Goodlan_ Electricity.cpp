#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

/*

6 2           arr[] size n = 6, k = 2
0 1 1 1 1 0   arr = [0, 1, 1, 1, 1, 0]

output = 2

*/

void print(vector<char> v)
{
	for(auto& i:v)
	{
		cout<<i<<",";
	}
}
//greedy
int pylons(int k, vector<int> arr) {
	int count=0, best_location=k-1, cover_location = 0;

	while(cover_location<arr.size())
	{
		if(arr[best_location] == 1)
		{

			count++;
			cover_location=(best_location+k-1+1);
			best_location= cover_location+k-1;
			if(best_location >= arr.size())
				best_location = arr.size()-1;
		}
		else
		{
			best_location--;
			if(best_location < 0 || cover_location-k+1 > best_location)
				return -1;
		}

	}
	return count;

}

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> v = {0,1,1,1,1,0};
	cout<<pylons(2,v)<<endl;
	
	return 0;
}