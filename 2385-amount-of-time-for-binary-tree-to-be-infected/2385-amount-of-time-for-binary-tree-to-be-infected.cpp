class Solution {
public:
    int ans = 0;

    void graph(TreeNode* root, vector<vector<int>>& adj) {
        if (root == NULL) {
            return;
        }

        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }

        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        graph(root->left, adj);
        graph(root->right, adj);
    }

    void dfs(vector<vector<int>>& adj, int start, vector<bool>& visited) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                int u = q.front();
                q.pop();
                visited[u] = true;

                for (int i = 0; i < adj[u].size(); i++) {
                    if (!visited[adj[u][i]])
                        q.push(adj[u][i]);
                }
            }
            ans++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        // create graph of the given tree
        vector<vector<int>> adj(100001);
        graph(root, adj);

        // start dfs
        vector<bool> visited(100001, false);
        dfs(adj, start, visited);

        return ans - 1;
    }
};
