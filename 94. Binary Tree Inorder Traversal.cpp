// Recursively
// Inorder: left subtree -> root -> right subtree

// Iteratively
/*
Starting at the root node, we need to go down (root->left or root->right).
We need to visit the entire left subtree, then root, than the entire right subtree.

Say we have visited the entire left subtree, going back to root node is easy.
But what about nodes in the middle, say from 6 back to 4?
How do we go up? There is no node->parent.
We need some data structure to keep track of the path we took.
We could use vector, but since the new evaluated nodes will be visited
before old nodes, we can use stack to store the path.
    1
   /  \
  2    3
 / \   /\
4   5 7  9
 \      / \
  6    12 13
 / \
10 11 

How do we know which node to evaluate next? 
When do we need to go to the bottom left? Two conditions:
1) current node has left subtree.
2) left subtree has not been visited.
The second condition indicates that we need to keep trak of the visited nodes.
We can use map from node to bool but set is better.
*/

#include<vector>
#include<stack>
#include<set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        set<TreeNode*> visited;
        stack<TreeNode*> stack;
        vector<int> ans;

        if (root == nullptr) return ans;
        
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* top = stack.top();
            
            // Top has no left subtree
            if (top->left == nullptr) {
                ans.push_back(top->val);
                visited.insert(top);
                stack.pop();
                // Add top's right subtree to stack
                if (top->right != nullptr) {
                    stack.push(top->right);
                }
                continue; }
            
            // Top has left subtree and
            // its left subtree has been visited
            if (top->left != nullptr && visited.find(top->left) != visited.end()) {
                ans.push_back(top->val);
                visited.insert(top);
                stack.pop();
                // Add top's right subtree to stack
                if (top->right != nullptr) {
                    stack.push(top->right);
                }
                continue;
            }
            
            // Top has left subtree and
            // its left subtree has not been visited
            if (top->left != nullptr && visited.find(top->left) == visited.end()) {
                stack.push(top->left);
                continue;
            }
        }
        
        return ans;
    }
}; 