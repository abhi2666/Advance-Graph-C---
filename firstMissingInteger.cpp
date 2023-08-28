int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    int j = 1;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > 0)
        {
            if(A[i] != j)
            {
                return j;
            }
            j++;
        }
    }
    return j;
}


