class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()==1 || barcodes.size()==0)
            return barcodes;
        map<int,int>m;
        vector<int> v;
        for(auto i: barcodes)
            m[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i: m)
            pq.push({i.second,i.first});
        while(pq.top().first>0){
            pair<int,int>p=pq.top();
            pq.pop();
            v.push_back(p.second);
            p.first--;
            pair<int,int>p2=pq.top();
            pq.pop();
            if(p2.first>0){
                v.push_back(p2.second);
                p2.first--;
            }
            pq.push(p);
            pq.push(p2);
        }
        return v;
    }
};
