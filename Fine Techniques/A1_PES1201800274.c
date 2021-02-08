#include <stdio.h>
#define MAX 2000
#include <string.h>
#include <stdlib.h>

/*
typedef struct node{
	char key[MAX];
	struct node* left;
	struct node* right;
   struct node* parent;
   int tab_count;
}node_t;
*/

typedef struct node{
   char key[MAX];
   struct node* left;
   struct node* right;
}node_t;


typedef struct tree{
	node_t *root;
}tree_t;

//Linked list that stores the address of all parent nodes in the GPT alongwith their tab_count.
typedef struct linked_list{
   node_t *node;
   int tab_space;
   struct linked_list *next;
}list;

tree_t* tree_initialise(){
   tree_t* t_root=(tree_t*)malloc(sizeof(tree_t));
  	t_root->root=NULL;
   return t_root;
}

node_t* create_node(char* str, int count){
   node_t* node=(node_t*)malloc(sizeof(node_t));
   node->right=NULL;
   node->left=NULL;
   int copylen=strlen(str)-count-1; 
   memset(node->key,'\0',sizeof node->key);
   strncpy(node->key,str+count,copylen); 
   return node;
}

// Creating GPT using modified Struct which has tab_count and link to Parent node.
/*
node_t* create_node(char* str, int count){
   node_t* node=(node_t*)malloc(sizeof(node_t));
   node->right=node->left=node->parent=NULL;
   int copylen=strlen(str)-count-1;
   strncpy(node->key,&str[count],copylen);
   node->tab_count=count;   
   return node;
}

void gpt(tree_t* t_root){ 
   char str[MAX];
   node_t* parent=NULL;
   while(fgets (str, MAX, stdin)!=NULL){
      int count=0; 
      while(str[count]=='\t'){
         count++;
      }
      node_t* new=create_node(str,count);
      if(t_root->root==NULL){
         t_root->root=new;
      }
      else if(new->tab_count>parent->tab_count){
         new->parent=parent;
         parent->left=new;   
      }
      else if(new->tab_count==parent->tab_count){
         new->parent=parent->parent;
         parent->right=new;
      }
      else{
         while(parent->tab_count!=new->tab_count){
            parent=parent->parent;
         }
         new->parent=parent->parent;
         while(parent->right!=NULL){
            parent=parent->right;
         }
         parent->right=new;  
      }
      parent=new;   
   }
}
*/

//Adding a parent node to the linked list.
void add_node(list** head, node_t* parent, int parent_tab_count){
   list* lnode=(list*)malloc(sizeof(list));
   lnode->next=*head;
   *head=lnode;
   lnode->tab_space=parent_tab_count;
   lnode->node=parent;
}

//When tab_count of new node is greater than that of the last inserted node, the latest parent node added to the linked list with same number of tab_spaces is searched for in the linked list. 
node_t* search(list** head,int count){
   list* parent=*head;
   while(parent->tab_space!=count){
      parent=parent->next;
   }
   return parent->node;
}

void destroy_ll(list *head){
   if(head->next==NULL){
      free(head);
   }
   else{
      destroy_ll(head->next);
      free(head);
   }
}

//creating the GPT
void gpt(tree_t* t_root){
   char str[MAX];
   int parent_tab_count=0;
   node_t* parent=NULL;
   list **head=(list**)malloc(sizeof(list**));
   *head=NULL;
   while(fgets (str, MAX, stdin)!=NULL){
      int count=0; 
      while(str[count]=='\t'){
         count++;
      }
      node_t* new=create_node(str,count);
      if(t_root->root==NULL){
         t_root->root=new;
      }
      else if(count>parent_tab_count){
         parent->left=new;  
         add_node(head,parent,parent_tab_count);
      }
      else if(count==parent_tab_count){
         parent->right=new;
      }
      else{
         parent=search(head,count);
         while(parent->right!=NULL){ //once last parent node with same number of tab spaces is found, current node is added as sibling of that node.
            parent=parent->right;
         }
         parent->right=new;  
      }
      //node address and tab_count of last inserted node is kept track of.
      parent=new; 
      parent_tab_count=count;   
   }
   destroy_ll(*head);
   free(head);
}

void prolog(tree_t* t_root)
{
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("int opt;\n");
   printf("while(scanf(\"%%d\",&opt)!=EOF && opt!=0)\n");
   printf("{\n");
   printf("switch(opt)\n");
   printf("{\n");
   printf("case 1:\n");
   printf("printf(\"%s\\n\");\n",t_root->root->key);
}

void sibling(node_t*,int,tree_t*);

//If current node has a child node, then while loop with switch and cases occur else checking for siblings to add cases. Generating code for that recursively.
void child(node_t* node, int count,tree_t* t_root){
   if(node->left!=NULL){
      node_t* node1=node->left;
      printf("while(scanf(\"%%d\",&opt)!=EOF && opt!=0)\n");
      printf("{\n");
      printf("switch(opt)\n");
      printf("{\n");
      printf("case 1:\n");
      printf("printf(\"%s\\n\");\n",node1->key);
      child(node1,1,t_root);
   }
   else{
      printf("break;\n");
   }
   sibling(node,count,t_root);
}

/*
//Sibling code for modified node_t struct
void sibling(node_t* node,int count,tree_t* t_root){
   if(node->right!=NULL){
      count++;
      node=node->right;
      printf("case %d:\n",count);
      printf("printf(\"%s\\n\");\n",node->key);
      child(node,count,t_root);
   }
   else if(node->right==NULL && node->parent!=NULL){
      printf("}\n");
      printf("}\n");
      printf("break;\n");
   }
}
*/

//Checks if current node is last sibling of the first node in the tree.
int check(tree_t* t_root,node_t* node)
{
	node_t* parent=t_root->root;
   while(parent->right!=NULL){
      parent=parent->right;
   }  
   if(parent==node){
      return 0;
   }
   return 1;
}

//Called by child function to print all case for a switch statement when siblings exist in the tree. Child is called to check if sibling has a child of its own.
void sibling(node_t* node,int count, tree_t* t_root){
   if(node->right!=NULL){
      count++;
      node=node->right;
      printf("case %d:\n",count);
      printf("printf(\"%s\\n\");\n",node->key);
      child(node,count,t_root);
   }
   else if(node->right==NULL && check(t_root,node)){ // Used to close switch and while loops within the case  of another switch statement. However, this shouldnt happen when we encounter the last sibling of the first node, since the first switch and while loop arent within the case of a switch statement.
      printf("}\n");
      printf("}\n");
      printf("break;\n");
   }
}

void epilog(){
   printf("}\n");
   printf("}\n");
   printf("return 1;\n");
   printf("}\n");
}

/* 
//Traverses the entire tree and prints current node and its parent. This function can be used only with the modified tree node structure. 
void display(node_t* root){
   printf("Current node is %s :\n",root->key);
   if(root->parent==NULL){
      printf("Parent is NULL \n");
   }
   else{
      printf("Parent is %s \n",root->parent->key);
   }
   if(root->left!=NULL){
      display(root->left);
   }
   if(root->right!=NULL){
      display(root->right);
   }
}
*/

void destroy_tree(node_t* root){
   if(root->left!=NULL){
      destroy_tree(root->left);
   }
   if(root->right!=NULL){
      destroy_tree(root->right);
   }
   free(root);
}  

int main () {
   tree_t* t_root=tree_initialise();   
   gpt(t_root);
   //display(t_root->root);
   if(t_root->root!=NULL){
      prolog(t_root);
      child(t_root->root,1,t_root);
      epilog();
      destroy_tree(t_root->root);
   }
   free(t_root);
   return(0);
}

