struct BinaryTree{
	int data;
	struct BinaryTree * lchild;
	struct BinaryTree * rchild;
};

int IsBalancedBinaryTree(struct BinaryTree * bt, int &depth){
	if(bt == NULL){
		depth = 0;
		return 1;
	}
	
	int left_depth, right_depth;
	
	if(IsBalancedBinaryTree(bt->lchild, left_depth) && IsBalancedBinaryTree(bt->right, right_depth)){
		int depth_diff = left_depth - right_depth;
		if(depth_diff <= 1 && depth_diff >= -1){
			depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
			return 1;
		}
	}
	
	return 0;
}