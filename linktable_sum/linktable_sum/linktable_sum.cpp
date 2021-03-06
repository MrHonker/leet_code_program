// linktable_sum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {} 
};

//1. 创建链表首节点
ListNode * createListNode(void)
{
	ListNode * phead = NULL;
	phead = new ListNode(0);
	phead->next = NULL;
	return phead;
}

//2. 输入链表数据
void inputNodeData(ListNode * head, int data)
{
	cout << "intput node is " << head << " " << "input data is " << data << endl;
	ListNode *curList = head;
	//结点赋值
	while (curList->next != NULL)
	{
		curList = curList->next;
	}
	curList->next = new ListNode(data);
}

//3. 遍历打印链表
void printLinkNode(ListNode * head)
{
	ListNode * print_node = head;
	while (print_node != NULL)
	{
		cout << "ListNode data is " << print_node->val << endl;
		print_node = print_node->next;
	}
}

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		//表示进位
		int carry = 0;
		ListNode *sum_link_list = new ListNode(0);
		ListNode *p1 = l1, *p2 = l2, *cur = sum_link_list;

		while (p1 != NULL || p2 != NULL)
		{
			int x = (p1 != NULL) ? p1->val : 0;
			int y = (p2 != NULL) ? p2->val : 0;
			int sum = x + y + carry;
			carry = sum / 10;
			cur->next = new ListNode(sum%10);
			cur = cur->next;
			if (p1 != NULL)
			{
				p1 = p1->next;
			}
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
		if (carry > 0)
		{
			cur->next = new ListNode(carry);
			cur = cur->next;
			cur->next = NULL;
		}
		return sum_link_list->next;
	}
};


int main()
{
	Solution sol;
	ListNode *link_node_1 = createListNode();
	ListNode *link_node_2 = createListNode();
	
	inputNodeData(link_node_1, 1);
	inputNodeData(link_node_1, 2);
	inputNodeData(link_node_1, 3);
	inputNodeData(link_node_1, 5);
	inputNodeData(link_node_2, 4);
	inputNodeData(link_node_2, 4);
	inputNodeData(link_node_2, 8);
	//过滤掉link_node_1和link_node_2无数据的首节点
	link_node_1 = link_node_1->next;
	link_node_2 = link_node_2->next;
	ListNode *sum_result = sol.addTwoNumbers(link_node_1, link_node_2);
	printLinkNode(sum_result);
    return 0;
}

