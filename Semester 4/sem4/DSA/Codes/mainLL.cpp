//#include "LL_functions.h"
#include "circularLL.h"


int main()
{
	Node* head = NULL;
	insertAtTailC(head, 1);
	insertAtTailC(head, 2);
	insertAtTailC(head, 3);
	insertAtTailC(head, 4);
	insertAtTailC(head, 5);

	DisplayC(head);

	/*Node* head2 = NULL;
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 3);
	insert_at_tail(head, 4);
	insert_at_tail(head, 5);
	insert_at_tail(head, 6);
	insert_at_tail(head2, 8);
	insert_at_tail(head2, 9);
	Node* newHead = merge(head, head2);
	display(newHead);*/
	//makeIntersection(head, head2, 3);
	//display(head);
	//display(head2);
	//cout << intersection_at(head, head2);
	//Node* newHead = k_append(head, 3);
	//display(newHead);
	//makeCycle(head, 3);
	//cout << detectCycle(head) << endl;
	//removeCycle(head);
	//cout << detectCycle(head) << endl;
	//display(head);
	//insert_at_head(head, 4);
	//deletion(head, 1);
	//display(head);
	//std::cout << search(head, 3) << "\n";
	/*Node* newHead = reverse_list(head);
	display(newHead);
	display(head);*/

	//Node* newHead1 = reverse_list_k_nodes(head, 2);
	//display(newHead1);
	

	return 0;
}