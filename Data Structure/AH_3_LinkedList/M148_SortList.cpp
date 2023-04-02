// two pointer
class Solution {
public:
    ListNode* midElement(ListNode* head)
    {
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(slow->next!= NULL && (fast!= NULL && fast->next!= NULL))
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyNode= new ListNode(-1);
        ListNode* ptr1= head1;
        ListNode* ptr2= head2;
        ListNode* ptr3= dummyNode;
        while(ptr1!= NULL && ptr2!= NULL)
        {
            if(ptr1->val < ptr2->val)
            {
                ptr3->next= ptr1;
                ptr1= ptr1->next;
            }
            else
            {
                ptr3->next= ptr2;
                ptr2= ptr2->next;
            }
            ptr3= ptr3->next;
        }
        while(ptr1!= NULL)
        {
            ptr3->next= ptr1;
            ptr1= ptr1->next;
            ptr3= ptr3->next;
        }
        while(ptr2!= NULL)
        {
            ptr3->next= ptr2;
            ptr2= ptr2->next;
            ptr3= ptr3->next;
        }
        return dummyNode->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
       if(head== NULL || head->next== NULL)
       {
           return head;
       }
       ListNode* mid= midElement(head);
       ListNode* head2= mid->next;
       mid->next= NULL;
       ListNode* finalHead= merge(sortList(head), sortList(head2));
       return finalHead;
    }
};