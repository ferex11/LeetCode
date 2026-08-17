class Solution {
private:
  int n;
  TreeNode* f(int& ind, int depth, string& traversal) {
    if (ind >= n) {
      return nullptr;
    }
    int j = ind;
    while (j < n && traversal[j] == '-') {
      j++;
    }
    int dash = j - ind;
    if (dash != depth) {
      return nullptr;
    }
    ind = j;
    int num = 0;
    while (ind < n && isdigit(traversal[ind])) {
      num = num * 10 + (traversal[ind] - '0');
      ind++;
    }
    TreeNode* root = new TreeNode(num);
    root->left = f(ind, depth + 1, traversal);
    root->right = f(ind, depth + 1, traversal);
    return root;
  }
public:
  TreeNode* recoverFromPreorder(string traversal) {
    n = traversal.size();
    int ind = 0;
    int depth = 0;
    return f(ind, depth, traversal);
  }
};
