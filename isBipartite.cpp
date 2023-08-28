/*
Bipartite Grapgh is a graph in which you can color all the nodes in two colours where
no two adjancent nodes have same colours. This can be easily done by using BFS or DFS.

You Just have to assign colours properly and then check if for any node(if visited already)
have the the same colour as its parent node(from which we have gotten to that node).
*/

//////////// BFS ////////////////////

class Solution {
public:

    bool bfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = 1; // 1 and -1 will represent two colors
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            int color = vis[currNode];
            for (auto adjNode : graph[currNode]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = -color; // Assign the opposite color
                    q.push(adjNode);
                } else if (vis[adjNode] == color) {
                    // Means it is not bipartite
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int row = graph.size();
        vector<int> vis(row, 0);
        // Call BFS for all nodes
        for (int i = 0; i < row; i++) {
            if (!vis[i]) {
                bool res = bfs(i, vis, graph);
                if (!res) return false;
            }
        }
        return true;
    }
};

////////// DFS ///////////////

class Solution {
public:

    bool dfs(int node, int color,  vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = color;
        for(auto adjNode : graph[node])
        {
            if(!vis[adjNode]){
                if(dfs(adjNode, -color, vis, graph) == false) return false;
            }
            else if(vis[adjNode] == color){
                // mother fucker is already visited
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int row = graph.size();
        vector<int> vis(row, 0);
        // Call BFS for all nodes
        for (int i = 0; i < row; i++) {
            if (!vis[i]) {
                bool res = dfs(i, 1, vis, graph);
                if (!res) return false;
            }
        }
        return true;
    }
};
