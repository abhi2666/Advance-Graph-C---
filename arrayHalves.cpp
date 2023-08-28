#include <iostream>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int sevenIndex = -1;
        for(int i =0; i < n; i++)
        {
            cin>>a[i];
            if(a[i] == 7) sevenIndex = i;
        }
        if(sevenIndex == -1) {
            // no fucking 7 is there
            cout<<"no"<<endl;
            continue;
        }
        // else there is still a possibility
        int j = i, k = i;
        bool flag = true;
        while(j >= 0 && k < n)
        {
            if(a[j] != a[k]){
                flag = false;
                break;
            }
            j--;
            k++;
        }
        if(flag) cout<<"yes"<<endl;
        else if(k != n || i != 0) cout<<"no"<<endl;
        else cout<<"no"<<endl;

    }
	return 0;
}
