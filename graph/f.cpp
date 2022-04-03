class Solution {
public:
    vector<int>vis;
    unordered_set<int>cycle,safe;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
        vis.resize(graph.size(),false);
        vector<int>ans;
        
         for(int i=0;i<graph.size();i++){
           if(dfs(i,graph))ans.push_back(i);
        }
       
        return ans;
    }
    
    bool dfs(int g,vector<vector<int>>& graph){
        
       if(safe.find(g)!=safe.end())return true;
       if(cycle.find(g)!=cycle.end())return false;
        if(vis[g]){
            cycle.insert(g);
            return false;
        }
        vis[g]=true;
        for(auto a:graph[g]){
            if(!dfs(a,graph)){
                cycle.insert(g);
                return false;
            }
        }
        safe.insert(g);
        return true;
    }
};