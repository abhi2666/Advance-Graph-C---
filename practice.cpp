// #include <iostream>
// using namespace std;

// bool allsameElements(string s){
//     for(int i = 0 ;i < s.size()-1; i++)
//     {
//         if(s[i] != s[i + 1]) return false;
//     }
//     return true;
// }

// bool sameEvenOdd(string s){
//     int even = s[0];
//     int odd = s[1];
//     for(int i = 2 ; i < s.size(); i++)
//     {
//         if(i%2 == 0)
//         {
//             if(s[i] != even) return false;
//         }
//         else{
//             if(s[i] != odd) return false;
//         }
//     }
//     return true;
// }


// int main() {
// 	int t;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         cin>>s;
//         int n = s.size();
//         if(n %2 == 0){
//             // even size --> then check all the elements at even and odd indexes are same
//             if(sameEvenOdd(s)){
//                 cout<<"YES"<<endl;
//             }
//         }
//         else if(n%2 != 0)
//         {
//             //then all elements should be same
//             if(allsameElements(s)){
//                 cout<<"YES"<<endl;
//             }
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
// 	return 0;
// }




#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
	while(t--)
    {
        int n, k; // k -->swaps to be done
        cin>>n>>k;
        vector<int> motu, tomu;
        for(int i = 0; i < )
    }
	return 0;
}
