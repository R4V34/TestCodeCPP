/*
    You are given two non-empty linked lists representing two
    non-negative integers. The digits are stored in reverse order,
    and each of their nodes contains a single digit. Add the two
    numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sup_List1 = l1;
    ListNode* sup_List2 = l2;
    ListNode* sup_List = new ListNode();
    int n1, n2, ten = 0, i = 0;
    vector<ListNode*> vec;
    vec.push_back(sup_List);
    while (sup_List1 != nullptr || sup_List2 != nullptr || ten == 1) {
        n1 = sup_List1 != nullptr ? sup_List1 -> val : 0;
        n2 = sup_List2 != nullptr ? sup_List2 -> val : 0;

        ListNode* newList = new ListNode();
        vec.at(i) -> val = (n1 + n2 + ten) % 10;
        vec.at(i) -> next = newList;
        vec.push_back(newList);
        ten = (n1 + n2 + ten) / 10;

        if (sup_List1 != nullptr) sup_List1 = sup_List1 -> next;
        if (sup_List2 != nullptr) sup_List2 = sup_List2 -> next;
        i++;
    }

    vec.at(vec.size() - 2) -> next = nullptr;
    return vec.at(0);
}

string to_string(ListNode* List)
{
    ListNode* sup_List = List;
    string res = "{ ";
    do {
        int e = sup_List -> val;
        res += to_string(e) + ", ";
        sup_List = sup_List -> next;
    } while (sup_List != nullptr);
    return res.substr(0, res.size() - 2) + " }";
}

int main()
{
    vector<int> l1 = {9,9,9,9,9,9,9};
    vector<int> l2 = {9,9,9,9};
    if (l1.size() == 0 || l2.size() == 0) return -1;

    ListNode* List1;
    ListNode** sup_arr1 = new ListNode*[l1.size()];
    sup_arr1[l1.size() - 1] = new ListNode(l1[l1.size() - 1]);
    for (int i = l1.size() - 2; i >= 0; i--)
        sup_arr1[i] = new ListNode(l1[i], sup_arr1[i + 1]);
    List1 = sup_arr1[0];

    ListNode* List2;
    ListNode** sup_arr2 = new ListNode*[l2.size()];
    sup_arr2[l2.size() - 1] = new ListNode(l2[l2.size() - 1]);
    for (int i = l2.size() - 2; i >= 0; i--)
        sup_arr2[i] = new ListNode(l2[i], sup_arr2[i + 1]);
    List2 = sup_arr2[0];

    ListNode* resultList = addTwoNumbers(List1, List2);
    cout << to_string(List1) + "\n+\n" + to_string(List2) +
            "\n=\n" + to_string(resultList);

    delete [] sup_arr1;
    delete [] sup_arr2;
    return 0;
}
