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
    private: int n=0;
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp=head;
        while(head!=nullptr){
            n++;
            head=head->next;
        }
    }
    
    int getRandom() {
        int a=rand()%n;
        ListNode* x = temp;
        int ans;
        //cout<<n<<" ";
        while(x && a--){
            x=x->next;
        }
        if(x==nullptr){
            return 0;
        }
        ans=x->val;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as su ListNode* tempch:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */