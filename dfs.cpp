/*
you have given a array of vectors which represents a graph .

Impelement DFS
*/

class Solution {
  public:
    void dfs(int node, vector<int>&vis, vector<int>&ans, vector<int>adj[])
    {
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]) // traversing the vector at node index
        {
            // if there is a node which is not visited yet..then fuck it
            if(vis[it] == -1)
            {
                dfs(it, vis, ans, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V, -1);
        dfs(0, vis, ans, adj);
        return ans;
    }
};