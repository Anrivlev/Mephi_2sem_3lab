#include  <iostream>
#include <cassert>
#include  "binary_heap.h"
#include  "binary_tree.h"
#include "set.h"

void testBinaryHeap()
{
	BinaryHeap<int> bheap(5);
	assert(bheap.exist(5) == true);
	assert(bheap.getSize() == 1);
	assert(bheap.getMin() == 5);
	
	bheap.add(6);
	bheap.add(4);
	assert(bheap.getSize() == 3);
	assert(bheap.getMin() == 4);
	assert(bheap.exist(5) == true);
	assert(bheap.exist(6) == true);
	
	bheap.erase(4);
	assert(bheap.exist(4) == false);
	assert(bheap.getSize() == 2);
	assert(bheap.exist(5) == true);
	assert(bheap.exist(6) == true);
}
void testBinaryTree()
{
	BinaryTree<int> btree(5);
	assert(btree.exist(5) == true);
	assert(btree.getSize() == 1);
	assert(btree.minimum() == btree.maximum());
	
	btree.add(4);
	btree.add(6);
	assert(btree.exist(4) == true);
	assert(btree.exist(6) == true);
	assert(btree.getSize() == 3);
	assert(btree.minimum() == 4);
	assert(btree.maximum() == 6);
	
	btree.erase(4);
	assert(btree.exist(4) == false);
	assert(btree.exist(5) == true);
	assert(btree.exist(6) == true);
	assert(btree.getSize() == 2);
	assert(btree.minimum() == 5);
	assert(btree.maximum() == 6);
}
void testSet()
{
	Set<int> set(5);
	assert(set.exist(5) == true);
	assert(set.getSize() == 1);
	
	set.add(4);
	set.add(6);
	assert(set.exist(4) == true);
	assert(set.exist(5) == true);
	assert(set.exist(6) == true);
	assert(set.getSize() == 3);
	
	set.erase(5);
	assert(set.exist(4) == true);
	assert(set.exist(5) == false);
	assert(set.exist(6) == true);
	assert(set.getSize() == 2);
}

int main(int argc, const char *argv[])
{
	testBinaryHeap();
	testBinaryTree();
	testSet();
	system("pause");
	return 0;
}