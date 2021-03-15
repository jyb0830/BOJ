//
//  two_liquid.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/15.
//  acmicpc.net/problem/2470

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int n, liquid;
    int ans[2];
    vector<int> v;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>liquid;
        v.push_back(liquid);
    }
    sort(v.begin(), v.end());
    
    if(v.front()>0){
        ans[0]=v[0];
        ans[1]=v[1];
    }
    else if(v.back()<0){
        ans[0]=v[v.size()-2];
        ans[1]=v.back();
    }
    else{
        int sum=2000000000;
        
        for(int i=0;i<v.size()-1;i++){
            int start=i+1;
            int end=(int)v.size()-1;
            while(end>=start){
                int mid=(end+start)/2;
                if(abs(v[i]+v[mid])<sum) {
                    sum=abs(v[i]+v[mid]);
                    ans[0]=v[i];
                    ans[1]=v[mid];
                }
                
                if(abs(v[mid])<abs(v[i])){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
    }
    
    cout<<ans[0]<<" "<<ans[1]<<"\n";
    return 0;
}
