class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());

        ListNode* curr = head;

        while(curr){
            if(st.count(curr->val)){
                curr = curr -> next;
            }
            else
              break;
        }
        ListNode* newHead = curr;

        while(curr && curr->next){
            if(st.count(curr->next->val)){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return newHead;
    }
};