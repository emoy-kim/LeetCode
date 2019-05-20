#include <iostream>

using namespace std;

struct ListNode 
{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int carry;
    int digit_sum;

    void setCarryAndDigit() {
       if (digit_sum >= 10) {
           carry = 1;
           digit_sum -= 10;
       }
       else {
           carry = 0;
       }
    }

    ListNode* allocAndMoveNext(ListNode* res_digit) {
        res_digit->next = (ListNode*)malloc(sizeof(ListNode));
        res_digit->next->val = 0;
        res_digit->next->next = NULL;
        return res_digit->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1_digit = l1;
        ListNode *l2_digit = l2;
        ListNode *res_digit = (ListNode*)malloc(sizeof(ListNode));
        ListNode *answer = res_digit;

        carry = 0;
        digit_sum = 0;
        while (l1_digit && l2_digit) {
            res_digit = allocAndMoveNext(res_digit);

            digit_sum = l1_digit->val + l2_digit->val + carry;
            setCarryAndDigit();
            
            res_digit->val = digit_sum;
            
            l1_digit = l1_digit->next;
            l2_digit = l2_digit->next;
        }

        while (l1_digit) {
            res_digit = allocAndMoveNext(res_digit);

            digit_sum = l1_digit->val + carry;
            setCarryAndDigit();

            res_digit->val = digit_sum;
            
            l1_digit = l1_digit->next;
        }

        while (l2_digit) {
            res_digit = allocAndMoveNext(res_digit);

            digit_sum = l2_digit->val + carry;
            setCarryAndDigit();

            res_digit->val = digit_sum;
            
            l2_digit = l2_digit->next;
        }

        if (carry > 0) {
            res_digit = allocAndMoveNext(res_digit);
            res_digit->val = carry;
        }
        
        ListNode *dummy = answer;
        answer = answer->next;
        free(dummy);

        return answer;
    }
};