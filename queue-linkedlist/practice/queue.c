queue* new_queue() {
	queue* q = malloc(sizeof(queue));
	q->head = NULL;
	q->tail = NULL;
	
	return q;
}

int is_empty(queue *q) {
	return q->head == NULL;
}

void enqueue(queue *q, int item) {
	node *n = malloc(sizeof(node));
	n->next = NULL;
	n->val = item;
	
	if (is_empty(q)) {
		q->head = n;
		q->tail = n;
	}
	else{
		q->tail->next = n;
		q->tail = n;
	} 
}

int dequeue(queue *q) {
	if (is_empty(q))
		exit(EXIT_FAILURE);
	
	node* ret = q->head;
	q->head = ret->next;
	
	int val = ret->val;
	
	free(ret);
	
	return val;
}

int front(queue *q) {
	if (is_empty(q))
		exit(EXIT_FAILURE);
	
	return q->head->val;
}

int back(queue *q) {
	if (is_empty(q))
		exit(EXIT_FAILURE);
	
	return q->tail->val;
}
