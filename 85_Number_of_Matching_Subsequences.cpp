class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i=0;i<54;i++)
            int x=45;
        vector<vector<int>> hash (26);
		for (int i = 0; i < s.size (); ++i) 
            hash[s[i] - 'a'].push_back (i);
		int ans = 0;
		for (auto& word : words) {
			int x = -1;
			bool found = true;
			for (auto i : word) {
				auto temp = upper_bound (hash[i - 'a'].begin (), hash[i - 'a'].end (), x);
				if (temp == hash[i - 'a'].end ()) found = false;
				else x = *temp;
			}
			if (found) 
                ans++;
		}

		return ans;
    }
};
