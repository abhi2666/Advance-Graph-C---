/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.

Input:
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is
'b', 'd', 'a', 'c' Note that words are sorted
and in the given language "baa" comes before
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

*/

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        // we will first create a adj. list with the help of dictionary
        // how ? compare two strings at same time and find the first different chars
        // and on the basis of that we will create a graph that will be then be used by
        // topo sort algo
        vector<int> adj[K];
        for (int i = 0; i < dict.size() - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int mini = min(s1.size(), s2.size());
            for (int j = 0; j < mini; j++)
            {
                if (s1[j] != s2[j])
                {
                    // means you can put it into adjaceny list
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        // once graph is ready we can apply topo sort to it
        int indeg[K] = {0};
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
        string topo = "";
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
            topo+= ele;
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