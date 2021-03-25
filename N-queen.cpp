//
//  N-queen.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/22.
//  acmicpc.net/problem/9663

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, answer=0;
int p[15];
vector<int> path;

void back_tracking(int a, int b){
    stack<pair<int, int>> s;
    s.push(make_pair(a,b));
    while(!s.empty()){
        int row=s.top().first;
        int col=s.top().second;
        p[row]=col;
        s.pop();
        if(row==n-1){
            answer++;
            continue;
        }
        for(int i=0;i<n;i++){
            bool check=true;
            for(int j=0;j<=row;j++){
                if(i==p[j]) {
                    check=false;
                    break;
                }
                
                if(abs(row+1-j)==abs(i-p[j])) {
                    check=false;
                    break;
                }
                
            }
            if(!check) continue;
            
            s.push(make_pair(row+1, i));
        }
    }
    
}


int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        p[0]=i;
        back_tracking(0, i);
    }
    
    cout<<answer<<"\n";
    return 0;
}
