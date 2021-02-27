//
//  eight.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/27.
//  acmicpc.net/problem/1105

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int l, r, ans=0;
    vector<int> v_l, v_r;
    cin>>l>>r;
    int num=l;
    while(num!=0){
        v_l.push_back(num%10);
        num/=10;
    }
    
    num=r;
    while(num!=0){
        v_r.push_back(num%10);
        num/=10;
    }
    if(v_l.size()!=v_r.size()) {
        cout<<0<<"\n";
        return 0;
    }
    
    else{
        for(int i=(int)v_l.size()-1;i>=0;i--){
            if(v_l[i]==8 && v_r[i]==8) {
                ans++;
            }
            else if(v_l[i]==v_r[i]) continue;
            else break;
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
