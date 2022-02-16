vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    int n = quiet.size();
    vector<int> adj[n + 1];
    vector<int> ino(n + 1, 0);

    for (int i = 0; i < richer.size(); i++)
    {

        ino[richer[i][1]]++;
        adj[richer[i][0]].push_back(richer[i][1]);
    }
    vector<int> ans(n, 0);

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        ans[i] = i;
        if (ino[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        for (auto a : adj[node])
        {
            if (--ino[a] == 0)
                q.push(a);
            if (quiet[ans[a]] > quiet[ans[node]])
            {
                ans[a] = ans[node];
            }
        }
    }
    return ans;
}