/*
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix

Approach --> we have to look for any O at the first row, last row, first col and last col.
if there exists a O there then we just have to call for a DFS and mark all the zeroes that are 
immediate neighbour of it in LRTB directions and if there is O, then mark them as visited in 
another 2D array.

At the end we will all the O that have been visited and the remaining O will be changed to X.
*/

class Solution{

private:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<char>>&mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        vis[i][j] = 1;
        // now check for TDLR
        int rows[] = {0,-1,0,1};
        int cols[] = {-1,0,1,0};
        for(int k = 0; k < 4; k++)
        {
            int currRow = i + rows[k];
            int currCol = j + cols[k];
            if(currRow >= 0 && currRow < r && currCol >= 0 && currCol < c && mat[currRow][currCol] == 'O' && !vis[currRow][currCol])
            {
                // if these are the cases then call DFS
                dfs(currRow, currCol, vis, mat);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n, vector<int>(m, 0));

        // go for first row and last row at the same time
        for(int i = 0; i < m; i++)
        {
            if(mat[0][i] == 'O' && !vis[0][i])
            {
                dfs(0, i, vis, mat);
            }

            if(mat[n-1][i] == 'O' && !vis[n-1][i])
            {
                dfs(n-1, i, vis, mat);
            }
        }
        // now same for the first col and last col
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, vis, mat);
            }

            if(mat[i][m-1] == 'O' && !vis[i][m-1])
            {
                dfs(i, m-1, vis, mat);
            }
        }

        // at the end change all the non-visted O to X
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O' && !vis[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

