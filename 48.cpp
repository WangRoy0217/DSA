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


void transpose(vector<vector<int>>& matrix)
{
	int row = matrix.size(), col = matrix[0].size();
	for(int i=0;i<row;++i)
	{
		for(int j=i;j<col;++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}
void reverse(vector<vector<int>>& matrix)
{
	int row = matrix.size(), col = matrix[0].size();
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col/2;j++)
		{
			swap(matrix[i][j], matrix[i][col-1-j]);
		}

	}
}
void rotate(vector<vector<int>>& matrix)
{
	reverse(matrix);
	transpose(matrix);
}



int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
	rotate(v);
	print(v);
	
	return 0;
}