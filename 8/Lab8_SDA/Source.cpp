#include <fstream>
#include <iostream>
using namespace std;
ofstream FILE2("2.txt");
struct TNode
{
	int info; 
	struct TNode* left, *right;
};
typedef struct TNode Node;
void push(Node*& t, int a)
{
	if (t == NULL) 
	{
		t = (Node*)malloc(sizeof(Node)); 
		t->info = a; 
		t->left = t->right = NULL;
			return;
	}
	if (a > t->info) push(t->right, a); 
	else push(t->left, a); 
}

void showTree(Node* t)
{
	if (t == NULL) return;
	cout << t->info;
	showTree(t->right); 
}

void postorder(Node* t)
{	
	if (t == NULL) return; 
	postorder(t->left); 
	postorder(t->right); 
	FILE2 << t->info << endl;
	cout << t->info << "  ";
}

int main()
{
	setlocale(LC_ALL, "ukr");
	Node* tree = NULL;
	int size; 
	ifstream FILE("1.txt");
	FILE >> size;
	for (int i = 0; i < size; ++i)
	{
		int element=0;
		FILE >> element;
		push(tree, element);
	}
	FILE.close();
	cout << "Обхiд дерева: "<< endl;
	FILE2 << "Результат зворотнього обходу бінарного дерева: " << endl;
	postorder(tree);
	FILE2.close();
}