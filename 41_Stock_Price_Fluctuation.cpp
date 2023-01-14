class StockPrice {
    priority_queue<int> pq1;
    priority_queue<int,vector<int>, greater<int> > pq2;
    unordered_map<int,int> mp1,mp2; 
    int mx,curr;
public:
    StockPrice() {
        mx=curr=0;
    }
    
    void update(int timestamp, int price) {
        if(mp2.find(timestamp) != mp2.end()){       
            mp1[mp2[timestamp]]--;
            while(!pq1.empty() && mp1[pq1.top()] == 0)
                pq1.pop();
            while(!pq2.empty() && mp1[pq2.top()] == 0)
                pq2.pop();
        }
        
        mp2[timestamp] = price;  
        
        if(mp1[price]++ == 0){ 
            pq1.push(price);
            pq2.push(price);    
        }
        
        if(timestamp >= mx){ 
            mx = timestamp;
            curr = price;
        }
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return pq1.top();
    }
    
    int minimum() {
        return pq2.top();
    }
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
