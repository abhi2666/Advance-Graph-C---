/*
find the nodes between which if you remove the edge..it becomes a tree
Only one edge is to be removed... you have to give the very last answer 
means there can be multiple answers
*/

class Solution {
public:

    void bfs(int index, vector<int>&vis, vector<vector<int>>&nodes, vector<vector<int>>&edges)
    {
        vis[index] = 1;
        queue<pair<int, int>>q; // node and its parent
        q.push({index, -1});
        while(!q.empty())
        {
            // traverse all neighbours
            int currNode = q.front().first;
            int parent = q.front().second;
            for(auto it : edges[currNode])
            {
                if(!vis[it])
                {
                    //mark visited and store in queue
                    vis[it] = 1;
                    q.push({it, currNode});
                }
                else if(parent != it){
                    // there is a cycle
                    vector<int>v = {it, currNode};
                    nodes.push_back(v);
                }
            }

        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>nodes;
        int V = edges.size();
        vector<int>vis(V, 0);
        for(int i = 1; i < V+1; i++)
        {
            bfs(i, vis, nodes, edges);
        }
        sort(nodes.begin(), nodes.end());
        return nodes.back();
    }
};