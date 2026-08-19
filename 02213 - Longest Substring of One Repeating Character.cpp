class SegmentTree {
private:
  struct Node {
    char leftChar;
    char rightChar;
    int prefix;
    int suffix;
    int best;
    int len;
    Node() {
      leftChar = rightChar = '#';
      prefix = suffix = best = len = 0;
    }
    Node(char c) {
      leftChar = rightChar = c;
      prefix = suffix = best = len = 1;
    }
  };
private:
  int n;
  string s;
  vector<Node> tree;
  Node merge(Node& left, Node& right) {
    if (left.len == 0) {
      return right;
    }
    if (right.len == 0) {
      return left;
    }
    Node res;
    res.len = left.len + right.len;
    res.leftChar = left.leftChar;
    res.rightChar = right.rightChar;
    res.prefix = left.prefix;
    res.suffix = right.suffix;
    res.best = max(left.best, right.best);
    if (left.rightChar == right.leftChar) {
      res.best = max(res.best, left.suffix + right.prefix);
      if (left.prefix == left.len) {
        res.prefix = left.len + right.prefix;
      }
      if (right.suffix == right.len) {
        res.suffix = right.len + left.suffix;
      }
    }
    return res;
  }
  void build(int ind, int low, int high) {
    if (low == high) {
      tree[ind] =  Node(s[low]);
      return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    tree[ind] = merge(tree[2 * ind + 1], tree[2 * ind + 2]);
  }
  void update(int ind, int low, int high, int pos, char c) {
    if (low == high) {
      tree[ind] = Node(c);
      return;
    }
    int mid = low + (high - low) / 2;
    if (pos <= mid) {
      update(2 * ind + 1, low, mid, pos, c);
    } else {
      update(2 * ind + 2, mid + 1, high, pos, c);
    }
    tree[ind] = merge(tree[2 * ind + 1], tree[2 * ind + 2]);
  }
public:
  SegmentTree(int n, string& s) {
    this->n = n;
    this->s = s;
    tree.resize(4 * n);
    build(0, 0, n - 1);
  }
  void setValue(int pos, char c) {
    update(0, 0, n - 1, pos, c);
  }
  int getLen() {
    return tree[0].best;
  }
};
class Solution {
public:
  vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
    int n = s.size();
    int k = queryIndices.size();
    SegmentTree st(n, s);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      int pos = queryIndices[i];
      char c = queryCharacters[i];
      st.setValue(pos, c);
      ans.push_back(st.getLen());
    }
    return ans;
  }
};
