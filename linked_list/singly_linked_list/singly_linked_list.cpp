#include <iostream>

struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE *p = NULL;

void display_lined_list (NODE *head) {
        NODE *x = head; 
        std::cout << "\nDisplaying the linked list: \nhead -> ";
          
        while (x != NULL) {
                std::cout << x->data << " -> ";
                x = x->next;
        }
        std::cout << "NULL\n";
}

int main () {
	NODE *head , *p , *current;
	head = NULL;
	while (true) {
		char ans;
		std::cout << "Do you want to enter data (Y/N) : ";
		std::cin >> ans;
		if (ans != 'y' && ans != 'Y') {break;}
		p = (NODE*) malloc (sizeof(NODE));
		std::cout << "Please enter data : ";
		std::cin >> p->data;	// creating the node
		p->next = NULL;
		if (head == NULL) {
			head = p;
			current = p;
		}
		else {
			current->next = p;
			current = p;
		}
	}
	display_lined_list(head);
	return EXIT_SUCCESS;
}