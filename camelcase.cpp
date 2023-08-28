int camelcase(string s) {
    int totalWords = 1;
    for(char ch : s)
    {
        if(isUpper(ch)) totalWords++;
    }
    return totalWords;
}