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
        bool flag = false;
        for(int i=0; i<n; i++){
            if(vec[i]==s){
                cout << s << " - found" << endl;
                flag = true;
                break; 
            }
        }
        if(!flag){
            cout << s << " - not found" << endl;
        }
    }


    return 0;
}