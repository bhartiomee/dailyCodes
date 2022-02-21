#include <bits/stdc++.h>
using namespace std;
class DSU
{
  vector<int> parent, rank;
  public:
  DSU(int n)
  {
    for (int i = 0; i < n; i++)
    {
      parent.push_back(-1);
      rank.push_back(1);
    }
  }
  int find(int x)
  {
    if (parent[x] == -1)
      return x;
    return parent[x] = find(x);
  }

  void Unionn(int x, int y)
  {
    int px = find(x);
    int py = find(y);
    if (px != py)
    {
      if (rank[px] < rank[py])
      {
        parent[px] = py;
        rank[px] += rank[py];
      }
      else
      {
        parent[py] = px;
        rank[py] += rank[px];
      }
    }
  }
};
class Graph
{
  vector<vector<int>> edgeList;
  int V;

  public:
    Graph(int V)
    {
      this->V = V;
    }
    void addEdge(int v1, int v2, int w)
    {
      edgeList.push_back({v1, v2, w});
    }

    void krushkals()
    {
      sort(edgeList.begin(), edgeList.end());
      DSU s(V);
      int ans = 0;
      cout << "Following are the edges in the "
              "constructed MST"
          << endl;
      for (auto edge : edgeList)
      {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        // take that edge in MST if it does form a cycle
        if (s.find(x) != s.find(y))
        {
          s.Unionn(x, y);
          ans += w;
          cout << x << " -- " << y << " == " << w
              << endl;
        }
      }
      cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

int main()
{
  Graph g(4);
  g.addEdge(0, 1, 10);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);
  g.addEdge(2, 0, 6);
  g.addEdge(0, 3, 5);
  g.krushkals();
  return 0;
}