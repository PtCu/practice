bool is_complete(tree *root)
{
	queue q;
	tree *ptr;
	// 进行广度优先遍历（层次遍历），并把NULL节点也放入队列
	q.push(root);
	while ((ptr = q.pop()) != NULL)
	{
		q.push(ptr->left);
		q.push(ptr->right);
	}

	// 判断是否还有未被访问到的节点
	while (!q.is_empty())
	{
		ptr = q.pop();
		
		// 有未访问到的的非NULL节点，则树存在空洞，为非完全二叉树
		if (NULL != ptr)
		{
			return false;
		}
	}

	return true;
}