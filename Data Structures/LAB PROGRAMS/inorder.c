// Iterative function to perform in-order traversal of the tree
void inorderIterative(Node *root)
{
	// create an empty stack
	stack<Node*> stack;

	// start from root node (set current node to root node)
	Node *curr = root;

	// if current node is null and stack is also empty, we're done
	while (!stack.empty() || curr != nullptr)
	{
		// if current node is not null, push it to the stack (defer it)
		// and move to its left child
		if (curr != nullptr)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else
		{
			// else if current node is null, we pop an element from stack,
			// print it and finally set current node to its right child
			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";

			curr = curr->right;
		}
	}
}


void postOrderIterative(struct Node* root) 
{ 
    // Check for empty tree 
    if (root == NULL) 
        return; 
      
    struct Stack* stack = createStack(MAX_SIZE); 
    do
    { 
        // Move to leftmost node 
        while (root) 
        { 
            // Push root's right child and then root to stack. 
            if (root->right) 
                push(stack, root->right); 
            push(stack, root); 
  
            // Set root as root's left child   
            root = root->left; 
        } 
  
        // Pop an item from stack and set it as root     
        root = pop(stack); 
  
        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        if (root->right && peek(stack) == root->right) 
        { 
            pop(stack);  // remove right child from stack 
            push(stack, root);  // push root back to stack 
            root = root->right; // change root so that the right  
                                // child is processed next 
        } 
        else  // Else print root's data and set root as NULL 
        { 
            printf("%d ", root->data); 
            root = NULL; 
        } 
    } while (!isEmpty(stack)); 
} 
