class Solution {
private:
  #define pii pair<int, int>
  vector<vector<pii>> adj;
  vector<int> dist;
  const int mod = (int)1e9 + 7;
  int dfs(int node, int parent, int destination, vector<int>& dp) {
    if (node == destination) return 1;
    if (dp[node] != -1) return dp[node];
    int paths = 0;
    for (auto& it : adj[node]) {
      int adjNode = it.first;
      int wt = it.second;
      if (node == parent) continue;
      if (dist[adjNode] < dist[node]) {
        paths = (paths + dfs(adjNode, node, destination, dp) % mod) % mod;
      }
    }
    return dp[node] = paths % mod;
  }
public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    adj.resize(n + 1);
    for (auto& it : edges) {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dist.resize(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    dist[n] = 0;
    while (!pq.empty()) {
      auto [dis, node] = pq.top();
      pq.pop();
      for (auto& it : adj[node]) {
        int adjNode = it.first;
        int wt = it.second;
        if (wt + dis < dist[adjNode]) {
          dist[adjNode] = wt + dis;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    vector<int> dp(n + 1, -1);
    int countPaths = dfs(1, -1, n, dp) % mod;
    return countPaths;
  }
};
