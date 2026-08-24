#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

void binarySearch(int target){
    int l = 0, r = vec.size()-1, mid;
    bool flag = false;
    while(l<=r){
        mid = l + (r-l)/2;
        if(vec[mid]==target){
            flag = true;
            break;
        }
        else if(vec[mid]<target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    (flag) ? cout << "Found\n" : cout << "Not Found\n";
}

int lowerBound(int target){
    int l = 0, r = vec.size()-1, mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(vec[mid]==target){
            if(vec[mid-1]!=target) return mid;
            else r = mid - 1;

        }
        else if(vec[mid]<target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
}

int upperBound(int target){
    int l = 0, r = vec.size()-1, mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(vec[mid]==target){
            if(vec[mid+1]!=target) return mid+1;
            else l = mid + 1;
        }
        else if(vec[mid]<target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
}

int main(){

    int n;
    cin >> n;
    vec.resize(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());

    binarySearch(10);
    binarySearch(2);

    cout << lowerBound(2) << endl;
    cout << upperBound(2) << endl;
    cout << upperBound(2) - lowerBound(2) << endl;


    return 0;
}