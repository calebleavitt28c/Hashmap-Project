#include "HashMap.h"

HashMap::HashMap(int size)
{
	hashArray = new Node * [size]; //we need to initilize the array he gives it to us in zybooks
	for (int i = 0; i < size; i++)
	{
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;

}

HashMap::~HashMap()
{
	/* gonna look similar to the for loop in the constructor 
	When deleting the hashmap use a for loop to move through the array the use what
you used to delete the linked list last project on each part of the array.
Once all of the linked lists are deleted then you delete the array which is a lot easier.*/

	for (int i = 0; i < sizeOfArray; i++)
	{
		Node* eraseNode;
		while (hashArray[i] != nullptr)
		{
			eraseNode = hashArray[i]->next;
			delete hashArray[i];
			hashArray[i] = eraseNode;
		}
	}
	
	delete[] hashArray;


}

bool HashMap::IsKeyPresent(string const& key) const //you can't just search the whole array it would increase the bigO of the hashMap you have to search only where the key would have been placed or is placed
{
	int index = GenerateHash(key);	
	Node* searchNode = hashArray[index];

	while (searchNode != nullptr)
	{
		if (searchNode->key == key)
			return true;
		else
		{
			searchNode = searchNode->next;
		}
	}
	return false;
}

void HashMap::SetKeyValue(string const& key, int value)
{
	//if key is not present, add to map and then set value
	
	int index = GenerateHash(key);
	Node* current;

	if (hashArray[index] == nullptr)
	{
		Node* newNode = new Node;
		newNode->next = nullptr;
		hashArray[index] = newNode;
		newNode->key = key;
		newNode->value = value;
		return;
	}
	else
	{
		current = hashArray[index];

		while (current != nullptr)
		{
			if (current->key == key)
			{
				current->value = value;
				return;
			}
			current = current->next;
		}

	}
	Node* newNode = new Node;
	newNode->next = hashArray[index];
	hashArray[index] = newNode;
	newNode->value = 1;
	newNode->key = key;
	return;
}

bool HashMap::GetKeyValue(string const& key, int& value)
{
	//NOTE: GetKeyValue() returns a bool (true if the key is present in the map) and it ALSO "returns" 
	//the value of that key through the parameter "value". Notice that "value is a "pass by reference" parameter

	int index = GenerateHash(key);
	Node* current;

	if (hashArray[index] == nullptr)
	{
		value = 0;
		return false;
	}
	else
	{
		current = hashArray[index];
		while (current != nullptr)
		{
			if (current->key == key)
			{
				value = current->value;
				return true;
			}
			current = current->next;
		}
		return false;
	}

}

Iterator HashMap::begin()
{
	 //return the first node listed
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (hashArray[i] != nullptr)
		{
			return Iterator(i, hashArray, sizeOfArray);
		}
	}
		return Iterator();
}

Iterator HashMap::end()
{
	return Iterator(); // to pass nullptr the thing right after the end of the array
}

int HashMap::GenerateHash(string key) const
{
	//this determines which bucket we are gonna put this word in to. Then we'll have to put it in to the linked list the bucket holds

	const int INITIAL_HASH = 7; 
	int hashValue = INITIAL_HASH; 
	for (int i = 0; i < key.length(); i++)
	{
		hashValue += (hashValue * 17) + key.at(i);
	}

	return abs(hashValue % sizeOfArray); //we need to return abs();
	//this is needed just incase we pass a number too large which overflows and turns negative
}

