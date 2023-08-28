class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int idx, int vis[], vector<int>adj[]){
        vis[idx] = 1;
        queue<pair<int, int>>q; // element, parent(from where we have reached the current node)
        q.push({0, -1});

        while(!q.empty())
        {
            int item = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[item])
            {
                if(vis[it] == -1){
                    // you can pick the current element
                    q.push({it, item}); // element with parent
                }
                // if is already visited then check its parent 
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) { // do this for each node
        int vis[V] = {-1};
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == -1)
            {
                if(bfs(i, vis, adj)) return true;
            }
            
        }

        return false;
    }
};