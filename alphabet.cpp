//
//  alphabet.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/30.
//  acmicpc.net/problem/1987

#include <iostream>
#include <stack>
#include <vector>
#include <tuple>
using namespace std;

int r, c, answer=1;
vector<vector<int>> v;

pair<int, int> d[4]={make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0,-1)};

void back_tracking(int init){
    stack<tuple<int, int, int, int>> s;
    s.push(make_tuple(0, 0, 1<<init, 1));
    
    while(!s.empty()){
        int row= get<0>(s.top());
        int col= get<1>(s.top());
        int path = get<2>(s.top());
        int cnt = get<3>(s.top());
        if(cnt>answer) answer = cnt;
        s.pop();
        
        for(int i=0;i<4;i++){
            if(row+d[i].first<0 || row +d[i].first>=v.size() || col+d[i].second<0 || col + d[i].second>=v[0].size()){
                continue;
            }
            if((1<<v[row+d[i].first][col+d[i].second] & path) == 0){
                s.push(make_tuple(row+d[i].first, col+d[i].second, path|1<<v[row+d[i].first][col+d[i].second], cnt+1));
            }
        }
    }
}


int main(){
    cin>>r>>c;
    
    for(int i=0;i<r;i++){
        v.push_back(vector<int>());
        for(int j=0;j<c;j++){
            char ch;
            cin>>ch;
            v[i].push_back(ch-'A');
        }
    }
    
    back_tracking(v[0][0]);
    
    cout<<answer<<"\n";
    return 0;
}
