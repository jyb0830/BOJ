//
//  laboratory.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/18.
//  acmicpc.net/problem/14502

#include <iostream>
#include <queue>
using namespace std;

int map[8][8];
int temp[8][8];
int spread[8][8];
int row, col, ans=0;

void BFS(){
    queue<pair<int, int>> q;
    pair<int, int> tmp;
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            spread[i][j]=temp[i][j];
            if(temp[i][j]==2){
                q.push(make_pair(i,j));
            }
        }
    }
    
    while(!q.empty()){
        tmp.first=q.front().first;
        tmp.second=q.front().second;
        q.pop();
        
        if(tmp.first-1>=0&&spread[tmp.first-1][tmp.second]==0){         //위로 전염
            spread[tmp.first-1][tmp.second]=2;
            q.push(make_pair(tmp.first-1, tmp.second));
        }
        if(tmp.second+1<col&&spread[tmp.first][tmp.second+1]==0){       //오른쪽으로 전염
            spread[tmp.first][tmp.second+1]=2;
            q.push(make_pair(tmp.first, tmp.second+1));
        }
        if(tmp.first+1<row&&spread[tmp.first+1][tmp.second]==0){        //아래로 전염
            spread[tmp.first+1][tmp.second]=2;
            q.push(make_pair(tmp.first+1, tmp.second));
        }
        if(tmp.second-1>=0&&spread[tmp.first][tmp.second-1]==0){        //왼쪽으로 전염
            spread[tmp.first][tmp.second-1]=2;
            q.push(make_pair(tmp.first, tmp.second-1));
        }
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(spread[i][j]==0) count++;
        }
    }
    ans=max(count, ans);
}

void wall(int cnt, int a, int b){   //벽을 세울 때, 벽의 조합이 중복 되지 않도록 하기 위한 인덱스 a, b
    if(cnt==3){
        BFS();
        return;
    }
    
    for(int i=a;i<row;i++){
        if(i==a){
            for(int j=b;j<col;j++){
                if(temp[i][j]==0){
                    temp[i][j]=1;
                    wall(cnt+1, i, j);
                    temp[i][j]=0;
                }
            }
        }
        else{
            for(int j=0;j<col;j++){
                if(temp[i][j]==0){
                    temp[i][j]=1;
                    wall(cnt+1, i, j);
                    temp[i][j]=0;
                }
            }
        }
    }
}

int main(){
    cin>>row>>col;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[i][j];
            temp[i][j]=map[i][j];
        }
    }
    wall(0,0,0);
    cout<<ans<<"\n";
    return 0;
}
