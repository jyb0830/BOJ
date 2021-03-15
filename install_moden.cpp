//
//  install_moden.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/14.
//  acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m, house;
    vector<int> v;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>house;
        v.push_back(house);
    }
    sort(v.begin(),v.end());
    
    int left = 1;
    int right = v.back()-v.front();
    int d = 0;
    int ans = 0;
    
    while(left<=right){
        int mid = (left + right) / 2;
        int start = v.front();
        int cnt=1;
        
        for(int i=1;i<n;i++){
            d = v[i]-start;
            if(mid<=d){
                cnt++;
                start = v[i];
            }
        }
        
        if(cnt>=m){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
