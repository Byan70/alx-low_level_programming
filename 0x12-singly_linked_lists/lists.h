/**
* struct list_s - Singly Linked List
* @str: string - (malloc'ed string)
* @len: the string lenght
* @next: Points to the next node
*
* Description: Singly linked list node structure
* for Holberton project
*/
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
list_t *add_node(list_t **head, const char *str);

list_t *add_node_end(list_t **head, const char *str);

size_t print_list(const list_t *h);

size_t list_len(const list_t *h);

void free_list(list_t *head);
