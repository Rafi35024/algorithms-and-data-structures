#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++) 
        cin >> vec[i];
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int l = 0, r = n-1, mid = 0;
        bool flag = false;
        while(l<=r){
            mid = (l+r)/2;
            if(s==vec[mid]){
                cout << s << " - found\n";
                flag = true;
                break;
            } 
            else if(s<vec[mid]) r = mid-1;
            else if(s>vec[mid]) l = mid+1;
        }
        if(!flag){
            cout << s << " - not found\n";
        }
    }


    return 0;
}