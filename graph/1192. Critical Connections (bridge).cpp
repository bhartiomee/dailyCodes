class Solution
{
public:
    vector<int> vis, time_of_init, lowest_time;
    vector<vector<int>> ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto c : connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vis.resize(n, 0);
        time_of_init.resize(n, -1);
        lowest_time.resize(n, -1);
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            dfs(i, -1, adj, timer);
        }
        return ans;
    }

    void dfs(int node, int parent, vector<int> adj[], int timer)
    {
        vis[node] = 1;
        time_of_init[node] = lowest_time[node] = timer++;

        for (auto neigh : adj[node])
        {
            if (neigh == parent)
                continue;
            if (!vis[neigh])
            {
                dfs(neigh, node, adj, timer);
                lowest_time[node] = min(lowest_time[neigh], lowest_time[node]);
                if (lowest_time[neigh] > time_of_init[node]) //that means only node can visit neigh
                {
                    vector<int> tmp;

                    tmp.push_back(node);
                    tmp.push_back(neigh);

                    ans.push_back(tmp);
                }
            }
            else
            {
                lowest_time[node] = min(lowest_time[neigh], lowest_time[node]);
            }
        }
    }
};
