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
/*
#it is wrong when Case "aaabbbcc"
string IsValid(string s) {
    unordered_map<char,int> m;
    for(auto& c:s)
        m[c]++;
    unordered_map<int,int> occTime;
    for(auto& c:m)
        occTime[c.second]++;
    
    if(occTime.size() < 2)
        return "YES";
    else if(occTime.size() > 2)
        return "NO";
    else
    {
        auto first_itr = next(occTime.begin(),0);
        auto second_itr = next(occTime.begin(),1);

        if(abs(first_itr->first - second_itr->first)==1 
            && (first_itr->second==1 || second_itr->second==1))
        {
            return "YES";
        }
        if(abs(first_itr->first - second_itr->first)!=1)
        {
            if(first_itr->first==1 && first_itr->second==1)
                return "YES";
            if(second_itr->first==1 && second_itr->second==1)
                return "YES";
        }
    }

    return "NO";

}
*/
string isValid(string s) {
	unordered_map<char,int> m;
	for(auto& c:s)
		m[c]++;

	//create occurance map #it should be map for  the first_itr(min) & second_itr(max)
	map<int,int> occTime;
	for(auto& c:m)
		occTime[c.second]++;
	
	if(occTime.size() < 2)
		return "YES";
	else if(occTime.size() > 2)
		return "NO";
	else
	{
		auto first_itr = next(occTime.begin(),0);
		auto second_itr = next(occTime.begin(),1);
		//Case that |a-b| is equal to 1, a
		if((second_itr->first - first_itr->first ==1) 
			&& (second_itr->second==1))
		{
			return "YES";
		}
		//
		else
		{
			if(first_itr->first==1 && first_itr->second==1)
				return "YES";
			if(second_itr->first==1 && second_itr->second==1)
				return "YES";
		}
	}

	return "NO";

}

int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> v = {0,1,1,1,1,0};
	string s = "aaabbbcc";
	cout<<isValid(s)<<endl;
	
	return 0;
}