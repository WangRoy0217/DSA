/* 662 Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.


Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

*/


class Solution
{
public:
  vector<uint64_t> minimal; // Minimal id at each level i.e. left most node at that level.
  uint64_t dfs(TreeNode* root,uint64_t level, uint64_t id)
  {
    if(root == NULL)
      return 0;
    if(level == minimal.size())
      minimal.push_back(id);


    return max( {id-minimal[level]+1, dfs(root->left,level+1,2*id),
                dfs(root->right,level+1,2*id+1)} );

  }
  int widthOfBinaryTree(TreeNode* root)
  {
    return dfs(root,0,0);
  }
};