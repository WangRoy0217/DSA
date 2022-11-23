#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
void print(vector<int> &arr)
{
    for(auto& i:arr)
    {
        cout<<i<<",";
    }
    cout<<endl;
}
void separateNumbers(string s)
{
    string temp, ans;
    unsigned long long keynum;
    for(int i=0;i<s.size()/2;i++)
    {
        ans.push_back(s[i]);
        temp = ans;
        keynum = stoull(temp);
        while(temp.size() < s.size())
        {
            temp.append(to_string(++keynum));
        }
        if(temp==s)
        {
            cout<<"YES"<<" "<<ans<<endl;
            return;
        }

    }
    cout<<"NO"<<endl;
    return;
}

/*
//this method would be wrong in case "896528165896528166896528167";
void separateNumbers(string s) {
    uint32_t* keynum = NULL;
    int len = s.length();
    for(int i=1;i<=len/2;i++)
    {
        string temp = s.substr(0,i);
        string target = to_string(stol(temp) + 1);
        int step = target.length();
        string fetch = s.substr(i, step);
        cout<<target<<","<<fetch<<endl;
        if(fetch==target)
        {
            keynum = new uint32_t(stoul(temp));
            s = s.substr(i);
            cout<<s<<endl;
            break;
        }
    }
    if(keynum == NULL)
    {
        cout<<"NO"<<endl;
        delete keynum;
        return;
    }
    for(uint32_t i=(*keynum)+1;s.length()>0;i++)
    {
        
        string target = to_string(i);
        string fetch = s.substr(0,target.length());
        if(target!=fetch)
        {
            cout<<"NO"<<endl;
            delete keynum;
            return;
        }
        s = s.substr(target.length());
    }

    cout<<"YES"<<" "<<*keynum<<endl;
    delete keynum;
}
*/

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5};
    //string s = "364360104364360105364360106";
    //string s = "896528165896528166896528167";
    string s;
    while(cin>>s)
    {
        separateNumbers(s);
    }

    

    

    
    return 0;
}