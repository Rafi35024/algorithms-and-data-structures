//024
#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void quick_sort(int l, int h){
    if(l<h){
        int pivot = vec[l];
        int i = h+1;
        for(int j=h; j>l; j--){
            if(vec[j]>=pivot){
                i--;
                swap(vec[i],vec[j]);
            }
        }
        swap(vec[i-1],vec[l]);
        int pi = i-1;
        quick_sort(l,pi-1);
        quick_sort(pi+1,h);
    }
}

int main() {

    int n,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        vec.push_back(x);
    }

    quick_sort(0, n-1);
    

    return 0;
}