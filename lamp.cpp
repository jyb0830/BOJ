//
//  lamp.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/21.
//  acmicpc.net/problem/1034

#include <iostream>
#include <vector>
using namespace std;

int row,col,k;
int lamp[50][50];
int ans[50];
vector<vector<int>> v;

void count_same_line(){
    for(int i=0;i<row;i++){
        int cnt=0;
        for(int j=0;j<col;j++){
            v[i].push_back(lamp[i][j]);
            if(lamp[i][j]==0) cnt++;
            ans[i]=1;
        }
        if(cnt>k || cnt%2 != k%2){
            v[i].clear();
            ans[i]=0;
        }
    }
    for(int i=0;i<row;i++){
        if(v[i].empty()) continue;
        for(int j=i+1;j<row;j++){
            bool check=true;
            for(int a=0;a<col;a++){
                if(v[i][a]!=v[j][a]){
                    check=false;
                    break;
                }
            }
            if(check){
                ans[i]++;
                v[j].clear();
                ans[j]=0;
            }
        }
    }
}


int main(){
    cin>>row>>col;
    char arr[col];
    for(int i=0;i<row;i++){
        v.push_back(vector<int>());
        ans[i]=0;
        for(int j=0;j<col;j++){
            cin>>arr[j];
            lamp[i][j]=arr[j]-'0';
        }
    }
    cin>>k;
    
    count_same_line();
    int num=0;
    for(int i=0;i<row;i++){
        num=max(num, ans[i]);
    }
    cout<<num<<"\n";
    return 0;
}
