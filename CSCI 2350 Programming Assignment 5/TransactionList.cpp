#include "TransactionList.h"

TransactionList::TransactionList(): head(nullptr), tail(nullptr)
{
}

TransactionList::~TransactionList()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

Transaction* TransactionList::removeTransaction()
{
	if (head == nullptr)
	{
		throw - 1;
	}
	if (head == tail)
	{
		Node* temp = head;
		head = nullptr;
		tail = nullptr;
		Transaction* transaction = temp->transaction;
		delete temp;
		return transaction;
	}
	Node* temp = head;
	head->next->prev = nullptr;
	head = head->next;
	Transaction* transaction = temp->transaction;
	delete temp;
	return transaction;
}

void TransactionList::addTransaction(Transaction* newTransaction)
{
	Node* newNode = new Node();
	newNode->transaction = newTransaction;

	string type = newNode->transaction->getTransactionType();

	if (type.compare("hire") == 0)
	{
		newNode->priority = 1;
	}
	else if (type.compare("hours") == 0)
	{
		newNode->priority = 2;
	}
	else if (type.compare("pieces") == 0)
	{
		newNode->priority = 3;
	}
	else if (type.compare("sales") == 0)
	{
		newNode->priority = 4;
	}
	else if (type.compare("termination") == 0)
	{
		newNode->priority = 5;
	}

	// If empty, add to list
	if (head == nullptr)
	{
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
		return;
	}

	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode->priority <= newNode->priority)
		{
			if (currentNode == tail)
			{
				break;
			}
			currentNode->next->prev = newNode;
			newNode = currentNode->next;
			currentNode->next = newNode;
			newNode->prev = currentNode;
			return;
		}
		currentNode = currentNode->next;
	}

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = nullptr;
	tail = newNode;
}

bool TransactionList::isEmpty()
{
	return head == nullptr;
}
