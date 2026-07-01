#include <bits/stdc++.h>
using namespace std;

// Section : Binary Tree
// Problem : Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        // Write solution logic here
        return result;
    }
};

// Helper function to build a tree from level-order string representation (e.g. "1 null 2 3")
TreeNode* buildTree(const string& input) {
    if (input.empty()) return nullptr;
    vector<string> values;
    stringstream ss(input);
    string val;
    while (ss >> val) {
        values.push_back(val);
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
        vector<vector<int>> result = solver.levelOrder(root);
        
        // Print 2D vector result as flat space-separated list
        bool first = true;
        for (size_t i = 0; i < result.size(); i++) {
            for (size_t j = 0; j < result[i].size(); j++) {
                if (!first) cout << " ";
                cout << result[i][j];
                first = false;
            }
        }
        cout << "\n";
        
        freeTree(root);
    }

    return 0;
}