//
//  swap_digit_xx.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/01.
//  acmicpc.net/problem/1039

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<string, int> > q;
int visit[1000001][11];
int main(){
    memset(visit, 0, sizeof(visit));
    string str;
    int K, ans=0;
    cin >> str >> K;
    
    q.push(make_pair(str, 0));
    while(!q.empty()){
        pair<string, int> cur = q.front(); q.pop();
        if(cur.second == K) {
            ans = max(ans, stoi(cur.first));
            continue;
        }
        string curStr = cur.first;
        for(int i=0; i<curStr.size()-1; i++){
            for(int j=i+1; j<curStr.size(); j++){
                swap(curStr[i], curStr[j]);
                if(curStr[0] == '0' || visit[stoi(curStr)][cur.second+1]) {
                    swap(curStr[i], curStr[j]);
                    continue;
                }
                q.push(make_pair(curStr, cur.second+1));
                visit[stoi(curStr)][cur.second+1] = 1;
                swap(curStr[i], curStr[j]);
            }
        }
    }
    if(ans == 0) cout << "-1";
    else cout << ans;
}
