//
//  make_password.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/26.
//  acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//a c i s t w
int l, c;
vector<char> v;

void back_tracking(int a){
    stack<pair<int, int>> s;
    int path[15];
    
    s.push(make_pair(1,a));
    while(!s.empty()){
        int cnt=s.top().first;
        int idx=s.top().second;
        path[cnt-1]=idx;
        s.pop();
        if(cnt==l){
            int vowel_cnt=0;
            for(int i=0;i<l;i++){
                if(v[path[i]]=='a' || v[path[i]]=='e' || v[path[i]]=='i' || v[path[i]]=='o' || v[path[i]]=='u'){
                    vowel_cnt++;
                }
            }
            if(vowel_cnt>=1 && l-vowel_cnt>=2){
                for(int i=0;i<l;i++) cout<<v[path[i]];
                cout<<"\n";
            }
        }
        
        for(int i=(int)v.size()-1;i>idx;i--){
            if(c-i<l-cnt) continue;
            
            s.push(make_pair(cnt+1, i));
        }
    }
}

int main(){
    cin>>l>>c;
    
    for(int i=0;i<c;i++){
        char word;
        cin>>word;
        v.push_back(word);
    }
    sort(v.begin(), v.end());
    
    for(int i=0;c-i>=l;i++){
        back_tracking(i);
    }
    
    return 0;
}
