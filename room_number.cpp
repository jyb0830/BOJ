//
//  room_number.cpp
//  BOJ
//
//  Created by 지영본 on 2021/04/09.
//  acmicpc.net/problem/1082

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, money;
    vector<char> answer;
    cin>>n;
    vector<pair<int,int>> cost;
    int c_arr[n];
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        cost.push_back(make_pair(num, i));
        c_arr[i]=num;
    }
    cin>>money;
    
    sort(cost.begin(), cost.end());
    
    if(n==1){
        cout<<0<<"\n";
        return 0;
    }
    
    if(cost[0].second==0){  //가장 가격이 저렴한 숫자가 '0'일 경우 --> 그 다음 저렴한 숫자를 첫 번째로 넣고 나머지를 전부 0으로 채운다.
        if(cost[1].first>money){    //두 번째로 저렴한 숫자가 가지고 있는 돈보다 비쌀때 답은 0 하나이다.
            cout<<0<<"\n";
            return 0;
        }
        
        answer.push_back('0'+cost[1].second);
        money-=cost[1].first;
        
        for(int i=0;i<(money/cost[0].first);i++){
            answer.push_back('0');
        }
        money%=cost[0].first;
    }
    else{   //가장 가격이 저렴한 숫자가 '0'이 아닌 경우 --> 그 숫자를 가지고 있는 돈만큼 채운다.
        for(int i=0;i<(money/cost[0].first);i++){
            answer.push_back('0'+cost[0].second);
        }
        money%=cost[0].first;
    }
    int idx=0;
    while(money>=0 && idx<answer.size()){
        for(int i=n-1;i>0;i--){
            if((i>answer[idx]-'0')&&(c_arr[i]-c_arr[answer[idx]-'0']<=money)){
                money= money - (c_arr[i]-c_arr[answer[idx]-'0']);
                answer[idx]='0'+i;
                break;
            }
        }
        idx++;
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
    }
    cout<<"\n";
    
    return 0;
}
