#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;
//https://www.hackerrank.com/challenges/three-month-preparation-kit-climbing-the-leaderboard/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=three-month-preparation-kit&playlist_slugs%5B%5D=three-month-week-seven
void print(vector<int> v)
{
	for(auto& i:v)
	{
		cout<<i<<",";
	}
}
/*
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int rank = 1;
    vector<int> results(player.size(), 0);
    int i = 0, j = player.size() - 1;
    while(j>=0)
    {
    	if(player[j] >= ranked[i])
    	{
    		results[j] = rank;
    		j--;
    		continue;
    	}
    	else if(i == ranked.size()-1)
    	{
    		results[j] = rank+1;
    		j--;
    		continue;
    	}
    	//#
    	if( i < ranked.size()-1)
    	{
    		if(ranked[i] != ranked[i+1])
    			rank++;
    		i++;
    	}
    }
    return results;
}

*/



vector<int> ClimbingLeaderboard(vector<int> ranked, vector<int> player) {
    int rank = 1;
    vector<int> results(player.size(), 0);
    int i = 0, j = player.size() - 1;
    while (j >= 0) 
    {
        // find correct rank corresponding to player score
        if (player[j] >= ranked[i]) 
        {
            // store rank in arr
            results[j] = rank;
            j--;
            continue;
        }
        else if (i == ranked.size() - 1) 
        {
            results[j] = rank + 1;
            j--;
            continue;
        }
        // increment i until end and rank when not duplicate
        if (i < ranked.size() - 1) 
        {
            if (ranked[i] != ranked[i+1])
                	rank++;
            i++;
        }
        // stop when player is empty
    }
    // return list of new ranks (expected in original order)
    return results;
}
int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> r = {100,90,90,80,75,70};
	vector<int> p = {50,65,77,90,102};
	vector<int> ans;
	string s = "aaabbbcc";
	ans = climbingLeaderboard(r,p);
	print(ans);
	
	return 0;
}