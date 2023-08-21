// binary search tree
int find_smallest(TreeNode* p){
	// base case
	if(p->left==NULL){
		return p->value;
	}
	
	// general case
	return find_smallest(p->left);
}

int count_odd(TreeNode* p){
	// base case
	if(p==NULL){
		return 0;
	}

	// general case
	// if someone solves the left, someone solves the right, then my solution would be:
	int result;
	result = ((p->value)%2);
	result = result + count_odd(p->left) + count_odd(p->right);
	return result;
}
