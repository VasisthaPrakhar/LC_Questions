static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
/* Definition for singly-linked list.
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* ans;
        int f=1;
        while(head!=NULL){
            ListNode* temp=head->next;
            if(f){
                head->next=NULL;
                    f--;
            }
            else{
                head->next=ans;
            }            
            ans=head;
            head=temp;
        }
       
        return ans;
    }
};