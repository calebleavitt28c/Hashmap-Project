#include "HashMap.h"

Iterator::Iterator(int index, Node** hashArray, int sizeOfArray)
{
	this->index = index;
	this->hashArray = hashArray;
	this->sizeOfArray = sizeOfArray;
	if (index < sizeOfArray)
	{
		current = hashArray[index];
	}
}

Iterator::Iterator() 
{
	index = 0;
	hashArray = nullptr;
	current = nullptr;
	sizeOfArray = 0;
}

string Iterator::operator*()
{
	//For the dereference iterator(*) return the key of that node.		
	return current->key;
}

void Iterator::operator++()
{
	// this one is the hardest
	// when your program crashes you don't want to simgle step through 500 elements. So what you do is go to the debug tap, windows, callstack. The code in black is what you wrote so you know what to go look at
	// use a for loop to be able to move through each element in the array
	//that way when you hit a bucket that points to null the function doesn't end but moves to the next element in the array so you can check the linked list in the next bucket

	// set current = nullptr to tell when you hit after the end of the array I don't know if you do this in this function 

	if (current->next != nullptr)
	{
		current = current->next;
		return;
	}
	else
	{
		if (index == sizeOfArray - 1)
		{
			current = nullptr;
			return;
		}

		index++;
		for (index; index < sizeOfArray; index++)
		{
			if (hashArray[index] == nullptr)
			{
				continue;
			}
			else
			{
				current = hashArray[index];
				return;
			}
		}
	}
}

bool Iterator::operator!=(Iterator& other)
{
	// not equal too returns true it is this guys job to tell you when you are at the end of the list
	if (this->current != other.current)
		return true;
	else
		return false;
}

bool Iterator::is_item()
{
	return true;
}

