/*
Topological Sort using BFS
We just have to put those elements ahead with lesser indegree first and same order is to
be followed.
*/

class Solution
{
public:
	// Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> topo;
		int indeg[V] = {0};
		// fill the indegree and then apply the regular BFS
		// as soon as you pick an element/ or find a neighbour reduce its indegree by 1.
		// To be done...
		for (int i = 0; i < V; i++)
		{
			for (auto it : adj[i])
			{
				indeg[it]++;
			}
		}

		// check for items with indegree 0 and put them in queue
		queue<int> q;
		for (int i = 0; i < V; i++)
		{
			if (indeg[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int ele = q.front();
			topo.push_back(ele);
			q.pop();
			for (int it : adj[ele])
			{

				indeg[it]--;
				if (indeg[it] == 0)
					q.push(it);
			}
		}

		return topo;
	}
};