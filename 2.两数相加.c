//写得有点蹩脚
//https://leetcode-cn.com/problems/add-two-numbers/
//medium
int max(int a, int b)
{
    return a > b ? a : b;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int v1[1000], v2[1000];
    int t1 = 0, t2 = 0;
    while (l1 != NULL) {
        v1[t1++] = l1->val;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        v2[t2++] = l2->val;
        l2 = l2->next;
    }
    int m = max(t1, t2);
    // printf("m=%d\n", m);
    int f = 0, now = 0;

    int ans[1000], at = 0;
    for (int i = 0; i < m || f != 0; i++) {
        int v11, v22;
        if (i >= t1)
            v11 = 0;
        else
            v11 = v1[i];
        if (i >= t2)
            v22 = 0;
        else
            v22 = v2[i];
        now = v11 + v22 + f;
        if (now < 10)
            f = 0;
        else
            f = 1;
        now = now % 10;
        ans[at++] = now;
    }
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode)); //梦开始的地方
    struct ListNode* r0 = ret;
    for (int i = 0; i < at - 1; i++) {
        ret->val = ans[i];
        ret->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        ret = ret->next;
        ret->next = NULL;
    }
    if (at > 0)
        ret->val = ans[at - 1];
    ret->next = NULL;
    return r0;
}