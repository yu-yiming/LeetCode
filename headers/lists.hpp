#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(x), next(nullptr) {}
};

ListNode* make_list(std::initializer_list<int> list) {
    ListNode* head(0);
    ListNode* curr = head;
    for (auto i : list) {
        curr = curr->next;
        curr = new ListNode(i);
    }
    curr = head->next;
    delete curr;
    return curr;
}

void free_list(ListNode* head) {
    ListNode* temp{};
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void traverse_list(ListNode* head, void (*visit)(int)) {
    while (head != nullptr) {
        visit(head);
        head = head->next;
    }
}

void print_list(ListNode* head) {
    if (head == nullptr) {
        std::cout << "[]";
        return;
    }
    std::cout << "[ ";
    while (head->next != nullptr) {
        std::cout << head->val << ' ';
    }
    std::cout << head->val << " ]";
}