//
//  tomato.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/08.
//

#include <iostream>
#include <queue>
using namespace std;

int m, n, day;
int arr[1001][1001];
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        
        if(row-1>=0&&arr[row-1][col]==0){
            q.push(make_pair(row-1, col));
            arr[row-1][col]=arr[row][col]+1;
        }
        if(col+1<m&&arr[row][col+1]==0){
            q.push(make_pair(row, col+1));
            arr[row][col+1]=arr[row][col]+1;
        }
        if(row+1<n&&arr[row+1][col]==0){
            q.push(make_pair(row+1, col));
            arr[row+1][col]=arr[row][col]+1;
        }
        if(col-1>=0&&arr[row][col-1]==0){
            q.push(make_pair(row, col-1));
            arr[row][col-1]=arr[row][col]+1;
        }
    }
}

int main(){
    cin>>m>>n;  //arr[n][m];
    bool ripen=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)
                q.push(make_pair(i, j));
            else if(arr[i][j]==0){
                ripen=false;
            }
        }
    }
    if(ripen==true){
        cout<<0<<"\n";
        return 0;
    }
    bfs();
    
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                cout<<-1<<"\n";
                return 0;
            }
            if(arr[i][j]>max)
                max=arr[i][j];
        }
    }
    cout<<max-1<<"\n";
    return 0;
}
