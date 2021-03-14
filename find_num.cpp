//
//  incresing_subsequence2.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/14.
//  acmicpc.net/problem/1920

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int b_search(int start, int end, int ans){
    if(end-start<0) return 0;
    
    int mid=(end+start)/2;
    if(v[mid]==ans) return 1;
    
    else if(v[mid]>ans) return b_search(start, mid-1, ans);
    
    else if(v[mid]<ans) return b_search(mid+1, end, ans);
    
    return 0;
}

int main(){
    int n, m, num;

    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    
    cin>>m;
    int arr[m], answer[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<m;i++){
        answer[i]= b_search(0,(int) v.size()-1, arr[i]);
    }
    
    for(int i=0;i<m;i++){
        cout<< answer[i]<<"\n";
    }
    
    return 0;
}
