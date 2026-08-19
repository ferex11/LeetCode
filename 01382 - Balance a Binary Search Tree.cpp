class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* construct(int low, int high, vector<int>& arr) {
        if (low > high) {
            return NULL;
        }
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = construct(low, mid - 1, arr);
        root->right = construct(mid + 1, high, arr);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        return construct(low, high, arr);
    }
};
