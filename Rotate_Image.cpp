/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
*/

class Solution {
public:
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
    //transpose before reverse -> 90 degrees (clockwise)
    //transpose after reverse -> 90 degrees (counterclockwise)
    transpose(matrix);
    reverse(matrix);
}
};