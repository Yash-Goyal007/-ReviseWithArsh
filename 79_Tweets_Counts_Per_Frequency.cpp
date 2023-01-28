class TweetCounts {
    map<string ,vector<int>> m;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int k;
        if(freq=="minute")
            k=60;
        else if(freq=="hour")
            k=3600;
        else
            k=86400;
        int end=endTime-startTime;
        vector<int> ans(ceil((end+1)/(k*1.0)),0);
        for(int i=0;i<m[tweetName].size();i++){
            if((m[tweetName][i]-startTime)<=end && (m[tweetName][i]-startTime)>=0)
                ans[ceil((m[tweetName][i]-startTime+1)/(k*1.0))-1]++;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
