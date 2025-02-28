/*
      232. Implement Queue using Stacks
*/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> queue;
    int top;
    MyQueue() {
       queue = stack<int>(); 
    }
    
    void push(int x) {
        if(queue.empty()) top = x;
        queue.push(x);
    }
    
    int pop() {
        int pop = top;
        stack<int> q;
        while(!queue.empty()) {
            q.push(queue.top());
            queue.pop();
        }     
        q.pop();
        top = q.empty()? 0: q.top();
        while(!q.empty()) {
            queue.push(q.top());
            q.pop();
        }
        return pop;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return queue.empty();
    }
};
