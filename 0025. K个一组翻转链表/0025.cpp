/*
思路一：c语言
看评论该方法使用栈，思路解法不错。
*/
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *listIter = head;
    struct ListNode *prevNode = NULL; //用prevNode指向入栈第一个元素的前一个元素.
    struct ListNode beforeHead = {0}; //单独在head前面又开了一个临时变量beforeHead，目的只是为了第一轮的while能和后面的while保持一致.
    struct ListNode **listStack = (struct ListNode **)malloc(sizeof(struct ListNode *) * k); //定义栈
    memset(listStack, 0, sizeof(struct ListNode *) * k);

    beforeHead.next = head;
    prevNode = &beforeHead;
    while (listIter != NULL) {  //循环直到链表末尾。
        int cnt = 0;
        while (cnt < k && listIter != NULL) { //入栈,链表listIter后移。
            listStack[cnt] = listIter;
            cnt++;
            listIter = listIter->next; 
        }
        if (cnt != k) { //如果入栈的个数已经不等于k，则直接循环结束。
            break;
        }
        while (cnt > 0) {  //出栈，prevNode->next指向出栈第一个元素，出栈第一个指向出栈第二个，出栈第二个指向出栈第三个...
            prevNode->next = listStack[cnt - 1];
            prevNode = prevNode->next;
            cnt--;
        }
        prevNode->next = listIter; //翻转完的子数组的最后一个节点的next即prevNode->next，指向后面剩余节点的第一个。
    }
    free(listStack);
    return beforeHead.next;
}

/*
思路二：cpp
参考官方题解
*/
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
