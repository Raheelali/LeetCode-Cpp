// Problem:  http://oj.leetcode.com/problems/path-sum/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22875143
// 1988lilong@163.com

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
    	if(root == NULL)
    	{
    		return false;
    	}

    	if(root->left == NULL && root->right == NULL)
    	{
    		return sum == root->val;
    	}

    	return hasPathSum(root->left, sum - root->val)
    		|| hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
//	  			  5
//	             / \
//	            4   8
//	           /     \
//	          11      4

	TreeNode n1(5);
	TreeNode n2(4);
	TreeNode n3(8);
	TreeNode n4(11);
	TreeNode n5(4);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n3.right = &n5;

	Solution slt;
	std::cout << slt.hasPathSum(&n1, 20) << std::endl;
	std::cout << slt.hasPathSum(&n1, 21) << std::endl;
}
