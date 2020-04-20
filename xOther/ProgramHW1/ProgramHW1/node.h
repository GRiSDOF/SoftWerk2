typedef struct _node
{
	struct _node* edge;
	int val;
}node;

node* connectNodes(node* root, node* leaf);
node* makeNode(int val);