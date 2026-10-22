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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr ){
            return nullptr;
        }
        ListNode* temp = head;
        int count = 0 ;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if(count == n) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        temp =head;
        int resultant = (count - n);
       
        for(int i =1;i<resultant;i++) {
            temp = temp->next;
        }
        ListNode* deletenode = temp->next;
            if(deletenode !=nullptr){
            temp->next = deletenode->next;
            delete deletenode;
            }
        return head;
    }
};