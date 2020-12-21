//
//  rotatingqueue.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/26.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

void shift_r(deque<int> &dq)
{
    dq.push_front(dq.back());
    dq.pop_back();
}
void shift_l(deque<int> &dq)
{
    dq.push_back(dq.front());
    dq.pop_front();
}

int r_count(deque<int> dq, int num)
{
    int count=0;
    deque<int> temp;
    temp=dq;
    while(temp.front()!=num)
    {
        shift_r(temp);
        count++;
    }
    return count;
}

int l_count(deque<int> dq, int num)
{
    int count=0;
    deque<int> temp;
    temp = dq;
    while(temp.front()!=num)
    {
        shift_l(temp);
        count++;
    }
    return count;
}


int main(){
    int N,M;
    int count=0;
    deque<int> dq;
    
    cin>>N>>M;
    int num[M];
    for(int i=0;i<N;i++)
        dq.push_back(i+1);
    
    for(int i=0;i<M;i++)
        cin>>num[i];
    
    for(int i=0;i<M;i++)
    {
        if(r_count(dq, num[i])>l_count(dq, num[i]))
        {
            count+=l_count(dq,num[i]);
            while(dq.front()!=num[i])
                shift_l(dq);
            
            dq.pop_front();
        }
        else
        {
            count+=r_count(dq, num[i]);
            while(dq.front()!=num[i])
                shift_r(dq);
            
            dq.pop_front();
        }
    }
    cout<<count<<"\n";
    
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10  --> 3 4 5 6 7 8 9 10 1 --> 10 1 3 4 5 6 7 8
