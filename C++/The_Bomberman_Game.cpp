#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


using namespace std;

void print(vector<string> v)
{
	for(auto& i:v)
		cout<<i<<endl;
	cout<<"##############"<<endl;
}

vector<string> bomberMan(int n, vector<string> grid)
{
	string full_row(grid[0].size(), 'O');
	vector<string> fullmap(grid.size(), full_row);
	if(n < 2 )
		return grid;
	if(n%2==0)
		return fullmap;
	else
	{
		vector<string> v = fullmap;
		int iter = n%4==3?1:2;
		while(iter>0)
		{
			for(int i=0;i<grid.size();i++)
			{
				for(int j=0;j<grid[0].size();j++)
				{
					if(grid[i][j] == 'O')
					{
						//center
						v[i][j] = '.';
						//left
						v[i][max(0, j-1)] = '.';
						//right
						v[i][min((int)grid[0].size()-1, j+1)] = '.';
						//top
						v[max(0, i-1)][j] = '.';
						//bottom
						v[min((int)grid.size()-1, i+1)][j] = '.';

					}
				}
			}
			grid = v;
			v = fullmap;
			iter--;
		}

	}
	
	return grid;
}

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<string> v = {".......",
						"...O.O.",
						"....O..",
						"..O....",
						"OO...OO",
						"OO.O..."};
	v = bomberMan(5, v);
	print(v);

	
	return 0;
}