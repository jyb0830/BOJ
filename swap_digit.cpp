//
//  swap_digit.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/23.
//  acmicpc.net/problem/1039

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

vector<int> v, max_v;
queue<pair<int, vector<int>>> q;
int k;

void v_swap(vector<int> v, int a, int b){
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}

bool v_same_check(vector<int> v1, vector<int> v2){
    bool check=true;
    for(int i=0;i<v1.size();i++){
        if(v1[i]!=v2[i]){
            check=false;
            break;
        }
    }
    return check;
}

void bfs(){
    q.push(make_pair(0, v));
    
    while(!q.empty()){
        if(q.front().first==k) return;
        
        if(v_same_check(max_v, q.front().second)) return;
        
        vector<int> temp(q.front().second);
        int idx=q.front().first;
        q.pop();
        for(int i=(int)temp.size()-1;i>=0;i++){
            if(temp[i]!=max_v[i]){
                for(int j=i;j>=0;j--){
                    if(temp[j]==max_v[i]){
                        v_swap(temp, i,j);
                        q.push(make_pair(idx+1, temp));
                        v_swap(temp,i,j);
                    }
                }
                break;
            }
            else{
                continue;
            }
        }
    }
}

int main(){
    int num;
    cin>>num>>k;
    
    while(num!=0){
        v.push_back(num%10);
        max_v.push_back(num%10);
        num/=10;
    }
    sort(max_v.begin(), max_v.end());
    
    bfs();
    int max_num=0;
    if(q.front().first==k){
        while(!q.empty()){
            int tmp_num=0;
            vector<int> temp(q.front().second);
            q.pop();
            for(int i=(int)temp.size()-1;i>=0;i--){
                tmp_num+=temp[i] * pow(10,i);
            }
            max_num=max(max_num, tmp_num);
        }
    }
    else{
        bool check=false;
        int count[10];
        for(int i=0;i<10;i++){
            count[i]=0;
        }
        for(int i=0;i<max_v.size();i++){
            count[max_v[i]]++;
        }
        for(int i=0;i<10;i++){
            if(count[i]>1) check=true;
        }
        if(!check || (k-q.front().first)%2!=0){
            v_swap(max_v, 0, 1);
        }
        int max_num=0;
        for(int i=(int)max_v.size()-1;i>=0;i--){
            max_num+=max_v[i]*pow(10,i);
        }
    }
    
    cout<<max_num<<"\n";
    return 0;
}
