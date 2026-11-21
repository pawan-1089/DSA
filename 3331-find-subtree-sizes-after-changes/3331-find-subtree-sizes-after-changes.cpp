class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; i++) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);

        // Step 1: DFS on original tree to determine new parents simultaneously
        auto findNewParents = [&](auto& self, int u) -> void {
            int ch = s[u] - 'a';
            int prevAncestor = lastSeen[ch];

            if (u != 0 && prevAncestor != -1) {
                newParent[u] = prevAncestor;
            }

            lastSeen[ch] = u;
            for (int v : origAdj[u]) {
                self(self, v);
            }
            lastSeen[ch] = prevAncestor; // Backtrack
        };

        findNewParents(findNewParents, 0);

        // Step 2: Build the final tree and compute subtree sizes
        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; i++) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto calcSizes = [&](auto& self, int u) -> int {
            for (int v : finalAdj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        calcSizes(calcSizes, 0);
        return ans;
    }
};
