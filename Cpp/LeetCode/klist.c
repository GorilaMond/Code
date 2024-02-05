struct ListNode {
    int val;
    struct ListNode *next;
};

main() {
    struct ListNode *lists[3];
    lists[0] = {1, &{4, &{5, 0}}};
}