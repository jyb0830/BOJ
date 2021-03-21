//
//  good_number.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/19.
//  acmicpc.net/problem/1060

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int64_t max_num=9223372036854775807;

int main(){
    int l,n;
    cin>>l;
    int64_t arr[l+1], cnt=0;
    vector<pair<int64_t, int64_t>> v, sector, good, answer;
    arr[0]=0;
    for(int i=1;i<l+1;i++){
        cin>>arr[i];
        answer.push_back(make_pair(0, arr[i]));
        cnt++;
    }
    cin>>n;
    for(int i=0;i<l;i++){
        if(arr[i+1]-arr[i]==1) {
            continue;
        }
        if(arr[i+1]-arr[i]==2){
            answer.push_back(make_pair(0, arr[i+1]-1));
            cnt++;
            continue;
        }
        v.push_back(make_pair(arr[i]+1, arr[i+1]-1));
        good.push_back(make_pair(arr[i+1]-arr[i]-2, 0));
    }
    for(int i=0;i<v.size();i++){
        sector.push_back(make_pair(arr[i+1]-arr[i]-2, i));
    }
    if(!sector.empty()){
        while(cnt<n){
            sort(sector.begin(), sector.end());
            int64_t idx = sector[0].second;
            if(sector[0].first==max_num){
                break;
            }
            
            int64_t size = v[idx].second-v[idx].first+1;
            if(good[idx].second==(v[idx].second-v[idx].first)/2){
                if((v[idx].second-v[idx].first+1)%2==1){
                    answer.push_back(make_pair(good[idx].first, v[idx].first+good[idx].second));
                    good[idx].first=max_num;
                    sector[0].first=good[idx].first;
                    cnt++;
                    continue;
                }
                else{
                    answer.push_back(make_pair(good[idx].first, v[idx].first+good[idx].second));
                    answer.push_back(make_pair(good[idx].first, v[idx].second-good[idx].second));
                    good[idx].first=max_num;
                    sector[0].first=good[idx].first;
                    cnt+=2;
                    continue;
                }
            }
            else{
                answer.push_back(make_pair(good[idx].first, v[idx].first+good[idx].second));
                answer.push_back(make_pair(good[idx].first, v[idx].second-good[idx].second));
                good[idx].second++;
                good[idx].first= good[idx].second * (size-good[idx].second) + (size-good[idx].second-1);
                sector[0].first=good[idx].first;
                cnt+=2;
            }
        }
    }
    int plus=1;
    while(cnt<n){
        answer.push_back(make_pair(max_num, arr[l]+plus));
        plus++;
        cnt++;
    }
    sort(answer.begin(), answer.end());
    for(int i=0;i<n;i++){
        cout<<answer[i].second<<" ";
    }
    
    return 0;
}
