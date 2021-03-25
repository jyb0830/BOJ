//
//  lotto.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/25.
//

#include <iostream>
#include <stack>
using namespace std;

int n;
int lotto[13];
int path[6];
void back_tracking(int a){
    stack<pair<int, int>> s;
    s.push(make_pair(1, a));
    while(!s.empty()){
        int cnt=s.top().first;
        int idx=s.top().second;
        path[cnt-1]=idx;
        s.pop();
        if(cnt==6){
            for(int i=0;i<6;i++){
                cout<<lotto[path[i]]<<" ";
            }
            cout<<"\n";
            continue;
        }
        for(int i=n-1;i>idx;i--){
            if(n-idx<6-cnt) continue;
            
            else{
                s.push(make_pair(cnt+1, i));
            }
        }
    }
}

int main(){
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>lotto[i];
        }
        for(int i=0;n-i>=6;i++){
            back_tracking(i);
        }
        cout<<"\n";
    }
    
    return 0;
}
