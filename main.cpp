#include <iostream>
#include "binary_heap.h"
#include "binary_tree.h"
#include "set.h"



template<class T>
void BinaryHeapInterface(T root)
{
	BinaryHeap<T> bheap(root);
	
	int choice = 0;
	T elem = 0;
	
	while(true)
	{
		std::cout <<
			"1. Add element.\n"
			"2. Erase element.\n"
			"3. Exist element.\n"
			"4. Show binary heap.\n"
			"5. exit\n";
		std::cin >> choice;
		
		switch (choice)
		{
		case 1:
			if (!(std::cin >> elem))
			{
				std::cout << "\nINCORRECT INPUT!\n";
				exit(1);
			}
			bheap.add(elem);
			break;
		case 2:
			if (!(std::cin >> elem))
			{
				std::cout << "\nINCORRECT INPUT!\n";
				exit(1);
			}
			bheap.erase(elem);
			break;
		case 3:
			if (!(std::cin >> elem))
			{
				std::cout << "\nINCORRECT INPUT!\n";
				exit(1);
			}
			if(bheap.exist(elem) == true)
				{
					std::cout << elem << " exists";
				} else
				{
					std::cout << elem << " does not exist";
				}
			break;
		case 4:
			bheap.show();
			break;
		case 5:
			exit(0);
		default:
			std::cout << "INCORRECT INPUT!";
		}
		std::cout << "\n";
	}
}

template<class T>
void BinaryTreeInterface(T root)
{
	BinaryTree<T> btree(root);
	
	int choice = 0;
	T elem = 0;
	
	while(true)
	{
		std::cout <<
			"1. Add element.\n"
			"2. Erase element.\n"
			"3. Exist element.\n"
			"4. Show minimum.\n"
			"5. Show maximum.\n"
			"6. Show tree.\n"
			"7. exit\n";
		std::cin >> choice;
		
		switch(choice)
		{
			case 1:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n"; 
					exit(1);
				}
				btree.add(elem);
				break;
			case 2:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n";
					exit(1);
				}
				btree.erase(elem);
				break;
			case 3:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n";
					exit(1);
				}
				if(btree.exist(elem) == true)
				{
					std::cout << elem << " exists";
				} else
				{
					std::cout << elem << " does not exist";
				}
				break;
			case 4:
				std::cout << btree.minimum();
				break;
			case 5:
				std::cout << btree.maximum();
				break;
			case 6:
				btree.showDFS();
				break;
			case 7:
				exit(0);
			default:
				std::cout << "INCORRECT INPUT";
		}
		std::cout << "\n";
	}
}

template<class T>
void SetInterface(T initElem)
{
	Set<T> set(initElem);
	
	int choice = 0;
	T elem = 0;
	
	while(true)
	{
		std::cout <<
			"1. Add element.\n"
			"2. Erase element.\n"
			"3. Exist element.\n"
			"4. Show set.\n"
			"5. exit\n";
		std::cin >> choice;
		
		switch(choice)
		{
			case 1:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n";
					exit(1);
				}
				set.add(elem);
				break;
			case 2:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n";
					exit(1);
				}
				set.erase(elem);
				break;
			case 3:
				if (!(std::cin >> elem))
				{
					std::cout << "\nINCORRECT INPUT!\n";
					exit(1);
				}
				if(set.exist(elem) == true)
				{
					std::cout << elem << " exists";
				} else
				{
					std::cout << elem << " does not exist";
				}
				break;
			case 4:
				set.show();
				break;
			case 5:
				exit(0);
			default:
				std::cout <<"INCORRECT INPUT";
		}
		std::cout << "\n";
	}
}

int main()
{
	int choiceStructure = 0;
	int choiceElements = 0;
	int initInt = 0;
	double initReal = 0;
	
	std::cout << "1. Binary heap\n2. Binary tree\n3. Set\n";
	std::cout << "Choose type of data structure: ";
	std::cin >> choiceStructure;
	std::cout << "1. Integer\n2. Real\n";
	std::cout << "Choose type of elements: ";
	std::cin >> choiceElements;
	if(choiceElements == 1)
	{
		std::cout << "\nInput first element of structure: \n";
		std::cin >> initInt;
		switch(choiceStructure)
		{
			case 1:
				BinaryHeapInterface(initInt);
				break;
			case 2:
				BinaryTreeInterface(initInt);
				break;
			case 3:
				SetInterface(initInt);
				break;
			default:
				std::cout << "INCORRECT TYPE OF STRUCTURE";
				exit(1);
		}
	} else if (choiceElements == 2)
	{
		std::cout << "\nInput first element of structure: \n";
		std::cin >> initReal;
		switch(choiceStructure)
		{
			case 1:
				BinaryHeapInterface(initReal);
				break;
			case 2:
				BinaryTreeInterface(initReal);
				break;
			case 3:
				SetInterface(initReal);
				break;
			default:
				std::cout << "INCORRECT TYPE OF STRUCTURE";
				exit(1);
		}
	
	} else
	{
		std::cout << "INCORRECT TYPE OF ELEMENT";
	}
	
	return 0;
}