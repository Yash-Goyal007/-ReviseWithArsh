/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *temp=new ListNode(0),*curr=temp;
        temp->next=head;
        map<int,ListNode*> mp;
        int sum=0;
        while(curr){
            sum+=curr->val;
            if(mp.count(sum)){
                curr=mp[sum]->next;
                int p=sum+curr->val;
                while(p!=sum){
                    mp.erase(p);
                    curr=curr->next;
                    p+=curr->val;
                }
                mp[sum]->next=curr->next;
            }
            else
                mp[sum]=curr;
            curr=curr->next;
        }
        return temp->next;
    }
};
