#include <stdio.h>
#include <stdlib.h>

typedef
   struct _Node {
      struct _Node *left;
      struct _Node *right;
   } Node;

static void* return_arg(void* p)
{
   return p;
}

Node* make_node(void)
{
   Node *x = malloc(sizeof(Node));
   x->left = NULL;
   x->right = NULL;
   return x;
}

Node* temp;

void f(void)
{
   temp					= make_node();   // A
   temp->left			= make_node();   // B
   temp->right			= make_node();   // C
   temp->left->left		= make_node();   // D
   temp->left->right	= make_node();   // E
   temp->right->left	= make_node();   // F
   temp->right->right	= make_node();   // G

}

int g(void) 
{
	int *a = malloc(20 * sizeof(int));
	int n = a[10];
   a[5] = 42;
	if (a[5] == 42) 
	{
		printf("hello from frame3().  The answer is 42.\n");
	}
	else 
	{
		printf("hello from frame3().  The answer is not 42.\n");
	}
   a[0] = 0;
	n = a[  a[0] & 7  ];

	free(a);

	

	return n;
}

int main(void)
{
   f();

   int y = g();
   return 0;
}

