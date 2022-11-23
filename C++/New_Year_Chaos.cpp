#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

void print(vector<int> v)
{
	for(auto& i:v)
		cout<<i<<",";
	cout<<endl;
	cout<<"##############"<<endl;
}

void minimumBribes(vector<int> q)
{
	for(int i=0;i<q.size();i++)
	{
		if(q[i]-1-i>2)
		{
			cout<<"Too chaotic"<<endl;
			return;
		}
	}
	
	int numtoindex[q.size()+1];
	int count=0;
	for(int i=0;i<q.size();i++)
	{
		numtoindex[q[i]] = i+1;
	}
	for(int i=1;i<q.size()+1;i++)
	{
		if(numtoindex[i]>i)
		{
			for(auto iter=next(q.begin(), numtoindex[i]-1);iter>next(q.begin(), i-1); iter--)
			{
				swap(*iter, *prev(iter,1));
				numtoindex[*iter]++;
				count++;
			}
		}
	}
	cout<<count<<endl;

}



int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> v = {3,1,2,5,6,7,9,8,4};
	minimumBribes(v);
	
	return 0;
}