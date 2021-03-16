//
//  weight_limit.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/16.
//  acmicpc.net/problme/4963

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int island[52][52], visited[52][52];
pair<int, int> d[8];

void bfs(int h, int w){
    queue<pair<int, int>> q;
    q.push(make_pair(h, w));
    visited[h][w]=1;
    while(!q.empty()){
        int th=q.front().first;
        int tw=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int a=th+d[i].first;
            int b=tw+d[i].second;
            if(island[a][b]==1 && visited[a][b]==0){
                q.push(make_pair(a, b));
                visited[a][b]=1;
            }
        }
    }
    
}

int main(){
    int w, h;
    vector<int> answer;
    for(int i=-1, idx=0;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 && j==0) continue;
            d[idx]=make_pair(i, j);
            idx++;
        }
    }
    while(1){
        int cnt=0;
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                island[i][j]=0;
                visited[i][j]=0;
            }
        }
        cin>>w>>h;
        if(w==0 && h==0) break;
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                cin>>island[i][j];
            }
        }
        
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                if(island[i][j]==1 && visited[i][j]==0){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
    }
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<"\n";
        
    return 0;
}
