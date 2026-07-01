/*
 * Problem: Binary Tree Traversal
 * Section: Binary Tree
 *
 * Time Complexity: O(N) where N is the number of nodes in the tree.
 * Space Complexity: O(H) where H is the height of the tree (recursion stack space).
 *
 * Summary:
 * Performs preorder, inorder, and postorder traversals of a binary tree.
 * - Preorder: Node -> Left -> Right
 * - Inorder: Left -> Node -> Right
 * - Postorder: Left -> Right -> Node
 */

#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

// Section : Binary Tree
// Problem : Binary Tree Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraveller(root, result);
        return result;
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorderTraveller(root, result);
        return result;
    }
    vector<int> inorderTraveller(TreeNode *root) {
        vector<int> result;
        inorderTraveller(root, result);
        return result;
    }
private:
    void preorderTraveller(TreeNode *node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->val);
        preorderTraveller(node->left, result);
        preorderTraveller(node->right, result);
    }
    void postorderTraveller(TreeNode *node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        // L -> R -> N 
        
        preorderTraveller(node->left, result);
        preorderTraveller(node->right, result);
        result.push_back(node->val);
    }
    void inorderTraveller(TreeNode *node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        inorderTraveller(node->left, result);
        result.push_back(node->val);
        inorderTraveller(node->right, result);
    }
};

// Helper function to build a tree from level-order string representation (e.g. "[1,null,2,3]" or "1 null 2 3")
TreeNode* buildTree(const string& input) {
    if (input.empty()) return nullptr;
    vector<string> values;
    string current = "";
    for (char c : input) {
        if (c == '[' || c == ']' || c == ',' || isspace(c)) {
            if (!current.empty()) {
                values.push_back(current);
                current = "";
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        values.push_back(current);
    }
    if (values.empty() || values[0] == "null") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(values[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (i < values.size() && values[i] != "null") {
            curr->left = new TreeNode(stoi(values[i]));
            q.push(curr->left);
        }
        i++;
        
        if (i < values.size() && values[i] != "null") {
            curr->right = new TreeNode(stoi(values[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (getline(cin, line)) {
        TreeNode* root = buildTree(line);
        Solution solver;
        vector<int> result = solver.preorderTraversal(root);
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i + 1 == result.size() ? "" : " ");
        }
        cout << "\n";
        freeTree(root);
    }

    return 0;
}
