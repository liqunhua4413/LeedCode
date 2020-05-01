/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){  
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode* resHead = NULL; //该指针resHead所指位置不变，变的是下面的指针temp

    if(l1->val > l2->val){
        resHead = l2;
        l2 = l2->next;
    }
    else {
        resHead = l1;
        l1 = l1->next;
    }
    struct ListNode* temp = resHead; //重新建一个节点，保留头节点resHead不改变，因为下面还要返回resHead。

    while(l1 && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }

    if(l1) temp->next = l1;
    if(l2) temp->next = l2;
    return resHead;
}
