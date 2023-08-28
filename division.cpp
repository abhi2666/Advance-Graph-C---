// 1
// 4
// 4 1



int sum(int start, int end, vector<int>s)
{
    int add = 0;
    for(int i = start; i <= end; i++)
    {
        add += s[i];
    }
    return add;
}

int birthday(vector<int> s, int d, int m) {
    int i = 0, j = m-1;
    int count = 0;
    if(s.size() == 1) return 1;
    while(j < s.size())
    {
        if(sum(i, j, s) == d) count++;
        i++;
        j++;
    }    
    return count;
}