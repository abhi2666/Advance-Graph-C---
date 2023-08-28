/*
Dijkstra's Algorithm --> to find the shortest path from a node to all other nodes. 
We can implement it using priority queue and sets and queue, where sets are then best.

Note-> for a graph with any element being negative, the dijkstra's algo will not work.
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        // will store the distance and node
        vector<int>dist(V, INT_MAX);
        dist[S] = {0};
        // we will start with the very first node which is S
        pq.push({0, S}); // to reach node S from S you need not to move 

        while(!pq.empty())
        {
            auto item = pq.top();
            int distance = item.first;
            int node = item.second;
            pq.pop();
            // for this node check all its neighbours and their distance 
            for(auto it : adj[node])
            {
                int adjNode = it[0]; // for this node we will calculate its distance from S and will change if new distance is less
                int weight = it[1];
                if(distance+weight < dist[adjNode]){
                    dist[adjNode] = distance+weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
