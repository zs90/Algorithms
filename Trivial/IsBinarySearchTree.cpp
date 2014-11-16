struct BinaryTree{
	int data;
	struct BinaryTree * lchild;
	struct BinaryTree * rchild;
};

int IsBinarySearchTree(struct BinaryTree * bt){
	static int prev = MIN_INT;
	int is_left, is_right;
	
	if(bt == NULL)
		return 1;
	else{
		is_left = IsBinarySearchTree(bt->lchild);
		
		if(is_left == 0 || prev >= bt->data)
			return 0;
		prev = bt->data;	
		
		is_right = IsBinarySearchTree(T->rchild);
		
		return is_right;
	}
}