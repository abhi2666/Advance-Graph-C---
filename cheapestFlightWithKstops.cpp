/*
Cheapest Flights wihtin k stops.
Approach --> something similar to Dijkstra's but not dikjstra because it takes distance as the
primary factor while selecting the paths but here rather than smallest distance, we also want to
reach the dest. in k stops and hence stops will be given utmost priority.

we will use a queue {stops, {node, distance}} to store the nodes and the stops that you have reached
and will apply a BFS type solution and will keep an distance array to keep track of the smallest 
distance to reach a particular node as well.

If at any moment, your stops become greater than k then it implies no need to move any further.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we will store the directed graph 
        vector<pair<int, int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]}); // src, dest, distance
        }

        queue<pair<int, pair<int, int>>q; // stops, node, distance
        int dist[n];
        for(int i = 0; i < n; i++) dist[i] = 1e9;
        dist[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.second.first;
            int nodeDist = it.second.second;
            int stops = it.first;
            for(auto padosi : adj[node])
            {
                int currNode = padosi.first;
                int edgWeight = padosi.second;

                if(stops > k) continue; // already reached the max no. of stops hence can't move further
                if(nodeDist + edgWeight < dist[currNode])
                {
                    dist[currNode] = nodeDist + edgWeight;
                    q.push({stops+1, {currNode, dist[currNode]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};