List* initialize_list() {
    List* list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->number_of_nodes=0;
    return(list);
}

Node* create_node(int data) {
    Node* node=(Node*)malloc(sizeof(Node));
    node->prev=NULL;
    node->next=NULL;
    node->data=data;
    return(node);
}

void insert_front(List* dll, int data) {
    Node* temp=create_node(data);
    if(dll->head==NULL){
        dll->head=temp;
    }
    else{
        temp->next=dll->head;
        dll->head->prev=temp;
        dll->head=temp;
    }
    dll->number_of_nodes++;
}

void position_delete(List* dll, int pos){
    if(pos<0 || pos>=dll->number_of_nodes || dll->head==NULL){
    }
    else{
        Node* temp=dll->head;
        int ind=0;
        while(temp->next!=NULL && ind<pos){
            temp=temp->next;
            ind++;
        }
        if(ind==0){
            dll->head=temp->next;
            if(temp->next!=NULL){
                temp->next->prev=NULL;
            }
        }
        else{
            int len=dll->number_of_nodes-1;
            if(ind==len){
                temp->prev->next=NULL;
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
        }
        free(temp);
        dll->number_of_nodes--;
    }    
}

int search_list(List* dll, int key) {
    Node* temp=dll->head;
    if(temp==NULL){
        return(-1);
    }
    else{
        int pos=0;
        while(temp->next!=NULL && temp->data!=key){
            temp=temp->next;
            pos++;
        }
        if(temp->data==key){
            return(pos);
        }
        else{
            return(-1);
        }
    }
}
void display(List* dll) {
    if(dll->head==NULL){
        printf("EMPTY");
    }
    else{
        Node* temp=dll->head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

void destroy_list(List* dll) {
    if(dll->head==NULL){
    }
    else{
        Node* temp=dll->head;
        while(temp->next!=NULL){
            temp=temp->next;
            dll->head=temp;
            free(temp->prev);
        }
        free(temp);
    }
    free(dll);
}
