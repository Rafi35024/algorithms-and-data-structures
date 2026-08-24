//024
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin >> vec[i];
    
    for(int i=1; i<n; i++){
        int temp = vec[i];
        int ind = i;
        for(int j=i-1; j>=0; j--){
            if(vec[j]>temp){
                vec[j+1] = vec[j];
                ind = j;
            }
            else break;
        }
        vec[ind] = temp;
    }

    for(auto x : vec) cout << x << " ";


    return 0;
}