bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    //check if K rooms are enough for the following data 
    int count = 0;
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int i = 0, j = 0; 
    while(i < arrive.size() || j < depart.size())
    {
        // if end > start --> you need an extra room
        if(depart[j] > start[i])
        {
            count++;
            i++;
        }
        else if(start[i] >= depart[j])
        {
            j++;
            count--;
        }
    }
    if(count <= K) return true;
    else return false;
}
