


struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

void freetree(struct tree *root)
{
	if(root->left != NULL)
		freetree(root->left);
	if(root->right != NULL)
		freetree(root->right);
	FREE(root);
}

void randominsert(struct tree *head, struct tree *new)
{
	int way;
	struct tree *curr, *prev;
	prev = NULL;
	curr = head;

	while(curr != NULL)
	{
		prev = curr;
		way = rand()%2;
		if(way == 0)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}
	if(way == 0)
		prev->left = new;
	else
		prev->right = new;
}

void printtree(struct tree *head)
{
	struct tree *curr = head;
	if(head == NULL)
		return;

	printtree(curr->left);	
	printf("%d\n", curr->data);
	printtree(curr->right);
}

void test1()
{
	

	struct tree *head = (struct tree *)my_lastfit_malloc(sizeof(struct tree));
	free(head);
	
}

int comp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}



int main() 
{
	srand((unsigned int)time(NULL));

	//For default malloc, the number printed here will not match the two
	//below. For your malloc, all three should match. (The real malloc
	//steals some space that it never returns. Yours should always be
	//removing everything it creates and reducing brk).
	printf("original val brk: %p\n", sbrk(0));
	test1();
	printf("brk after  test1: %p\n", sbrk(0));


	return 0;
}
