#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node* next;
} node;

class linked_list{
	public: linked_list(){
		head = NULL;
	}

	public: node* new_node(int data){
		node* temp = new node;
		temp->data = data;
		temp->next=NULL;
		return temp;
	}

	public: void insert_node(int data){
		node* node_to_be_inserted = new_node(data);
		node* cur = new node;
		cur = head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = node_to_be_inserted;
	}

	public: void print_list(){
		node* cur = head;
		while(cur != NULL){
			cout << cur->data << " --> ";
			cur = cur->next;
		}
		cout << "NULL" << endl;
	}

	public: node* search(int val){
		node* cur = new node;
		cur = head;
		while((cur != NULL) && (cur->data != val)){
			cur = cur->next;
		}
		return cur;
	}

	public: node* head;

};

int main(){
	linked_list* list = new linked_list();
	list->head = list->new_node(10);

	list->insert_node(40);
	list->insert_node(12);
	list->insert_node(3);

	list->print_list();

	return 0;
}

