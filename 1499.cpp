
class Solution
{
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k)
  {
    priority_queue<pair<int, int>> q; // {y - x, x}    
    int ans = INT_MIN;
    for (const auto& p : points)
    {
      const int x = p[0], y = p[1];
      while (!q.empty() && x - q.top().second > k) 
        q.pop();
      if (!q.empty())
        ans = max(ans, x + y + q.top().first);
      q.emplace(y - x, x);
    }
    return ans;
  }
};


//using max heap
class Solution
{
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k)
  {
    priority_queue<pair<int,int>> max_heap;
    int ans = INT_MIN;
    for(auto& p:points)
    {
      int x = p[0];
      int y = p[1];
      while(!max_heap.empty() && x - max_heap.top().second > k)
        max_heap.pop();
      if(!max_heap.empty())
        ans = max({ans, x+y+max_heap.top().first});

      max_heap.emplace(y-x, x);
    }

    return ans;
  }
};

//using deque
class Solution
{
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k)
  {
    deque<pair<int,int>> q;
    int ans = INT_MIN;
    for(auto& p:points)
    {
      int x = p[0];
      int y = p[1];
      while(!q.empty() && x - q.front().second > k)
        q.pop_front();
      if(!q.empty())
        ans = max({ans, x+y+q.front().first});
      while(!q.empty() && y-x >= q.back().first)
        q.pop_back();
      q.emplace_back(y-x, x);
    }

    return ans;
  }
};
