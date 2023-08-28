/*
1, 2, 3, 4, 5
2, 1, 4
*/

vector<int> Solution::wave(vector<int> &a) {
    // for lexograpical order answer sorting is to be done
    sort(a.begin(), a.end());
    bool flag = true;
    for(int i = 0; i < a.size()-1; i++)
    {
        if(flag)
        {
            // check for ai > ai+1
            if(a[i] <= a[i+1]){
                swap(a[i], a[i + 1]);
                flag = !flag;
            }
        }
        else{
            if(a[i + 1] <= a[i])
           {
                swap(a[i+1], a[i]);
                flag = !flag;
            }
        }
    }
    return a;
}
