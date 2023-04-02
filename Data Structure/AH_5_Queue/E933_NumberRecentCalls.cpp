queue<int> q;

RecentCounter() {
}

int ping(int t) {
    
	q.push(t);
	   
    while(q.front() < t-3000)
        q.pop();
    
    return q.size();
}

// we can use stack.shift() =>delete the top of stack 