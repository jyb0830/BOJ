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

int main(){
    int l,n;
    cin>>l;
    
    int arr[l+1], cnt=0;
    vector<pair<int,int>> v, sector, good, answer;
    arr[0]=0;
    for(int i=1;i<l+1;i++){
        cin>>arr[i];
        cout<<"arr["<<i<<"] : "<<arr[i]<<"\n";
        answer.push_back(make_pair(0, arr[i]));
        cnt++;
    }
    cin>>n;
    for(int i=0;i<l;i++){
        v.push_back(make_pair(arr[i]+1, arr[i+1]-1));
        good.push_back(make_pair(arr[i+1]-arr[i]-2, 0));
    }
    for(int i=0;i<v.size();i++){
        sector.push_back(make_pair(arr[i+1]-arr[i]-2, i));
    }
    
    while(cnt<n){
        sort(sector.begin(), sector.end());
        int idx = sector[0].second;
        cout<<"크기 : "<<sector[0].first<<"  ";
        cout<<"idx : "<<idx<<"\n";
        int size = v[idx].second-v[idx].first+1;
        if(good[idx].second==(v[idx].second-v[idx].first+1)/2){
            cout<<"들어옴\n";
            if((v[idx].second-v[idx].first+1)%2==1){
                answer.push_back(make_pair(good[idx].first, v[idx].first+good[idx].second));
                good[idx].first=2100000000;
                cnt++;
                continue;
            }
            else{
                answer.push_back(make_pair(good[idx].first, v[idx].first+good[idx].second));
                answer.push_back(make_pair(good[idx].first, v[idx].second-good[idx].second));
                good[idx].first=2100000000;
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
    
    sort(answer.begin(), answer.end());
    for(int i=0;i<n;i++){
        cout<<answer[i].second<<" ";
    }
    cout<<"\n";
    
    return 0;
}
