class Solution {
public:
    vector<vector<int>> adj;
    vector<int> newParent, ans;

    void dfs(int node, vector<int>& last, string& s) {
        int ch = s[node] - 'a';

        int old = last[ch];

        if (old != -1) {
            newParent[node] = old;
        }

        last[ch] = node;

        for (int child : adj[node]) {
            dfs(child, last, s);
        }

        last[ch] = old;
    }

    void dfs2(int node, vector<vector<int>>& adj) {
        ans[node] = 1;

        for (int child : adj[node]) {
            dfs2(child, adj);
            ans[node] += ans[child];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newParent = parent;
        ans.resize(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Find new parents
        vector<int> last(26, -1);
        dfs(0, last, s);

        // Build modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        dfs2(0, newAdj);

        return ans;
    }
};