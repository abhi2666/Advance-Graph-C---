/*
Given an integer array A of size N.

You have to pick exactly B elements from
 either left or right end of the array A to get the maximum sum.
*/
int Solution::solve(vector<int> &A, int B)
{
    int sum = 0;
    // first element from start and B - 1 element from the last
    int i = 0, j = A.size() - B;
    for(int k = j; k < A.size(); k++)
    {
        sum += A[k];
    }

    int max_sum = sum;
    while(i < B)
    {
        sum += A[i];
        i++;
        sum -= A[j];
        j++;
        max_sum = max(max_sum, sum);
    }

    return max_sum;

}
