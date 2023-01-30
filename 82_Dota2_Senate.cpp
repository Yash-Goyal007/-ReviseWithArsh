class Solution {
public:
    string predictPartyVictory(string senate) {
        int dire=0, radiant=0, i=0;
        int temp1=0, temp2=senate[0];
        for(auto ch :senate){
            if (ch=='D') 
                dire++;
            else 
                radiant++;
        }
        while(dire != 0 && radiant != 0){
            if (temp1 == 0 || senate[i] == temp2){
			    temp2 = senate[i];
                senate.push_back(temp2);
                temp1++;
            }
            else{
                if (temp2 == 'D')
                    radiant--;
                else
                    dire--;
                temp1--;
            }
            i++;
        }
        return dire>radiant?"Dire":"Radiant";
    }
};
