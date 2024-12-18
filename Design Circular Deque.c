typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int val;
} Node;


typedef struct {
    Node* head;
    Node* tail;
    int size;
    int maxSize;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* dq=(MyCircularDeque*) malloc(sizeof(MyCircularDeque));
    dq->head = (Node*) malloc(sizeof(Node));
    dq->tail = (Node*) malloc(sizeof(Node));
    dq->head->next=dq->tail;
    dq->head->prev=NULL;
    dq->tail->prev=dq->head;
    dq->tail->next=NULL;
    dq->size=0;
    dq->maxSize=k;

    return dq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size==obj->maxSize) return false;
    Node* nn=(Node*) malloc(sizeof(Node));
    nn->val=value;
    nn->prev=obj->head;
    nn->next=obj->head->next;
    obj->head->next->prev=nn;
    obj->head->next=nn;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size==obj->maxSize) return false;
    Node* nn=(Node*) malloc(sizeof(Node));
    nn->val=value;
    nn->prev=obj->tail->prev;
    nn->next=obj->tail;
    obj->tail->prev->next=nn;
    obj->tail->prev=nn;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size==0) return false;
        
    Node* bck=obj->head->next;

    obj->head->next->next->prev=obj->head;

    obj->head->next=obj->head->next->next;
        
    obj->size--;
    free(bck);
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size==0) return false;
        
    Node* bck=obj->tail->prev;

    obj->tail->prev->prev->next=obj->tail;

    obj->tail->prev=obj->tail->prev->prev;
        
    obj->size--;
    free(bck);
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return obj->size == 0 ? -1 : obj->head->next->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return obj->size == 0 ? -1 : obj->tail->prev->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size==0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size==obj->maxSize;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Node* curr=obj->head;
    while(curr!=NULL) {
        Node* bck=curr;
        curr=curr->next;
        free(bck);
    }
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
