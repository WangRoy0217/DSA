/* 378. Kth Smallest Element in a Sorted Matrix
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).
Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2



*/
#include <bits/stdc++.h>


using namespace std;


int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int len = matrix.size();
    priority_queue<int> min_heap;

    for(int i=0;i<len;++i)
    {
        for(int j=0;j<len;++j)
        {
            min_heap.push(-1*matrix[i][j]);
        }
    }
    for(int i=0;i<k-1;++i)
        min_heap.pop();
    return -1*min_heap.top();
}

/*
    int m, n;
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r)
        {
            while (c >= 0 && matrix[r][c] > x) 
                --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
    
*/

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = { {1,5,9},
                                {10,11,13},
                                {12,13,15} };
    cout<<kthSmallest(arr, 8)<<endl;
    return 0;
}