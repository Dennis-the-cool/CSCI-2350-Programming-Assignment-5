#include "TransactionList.h"

TransactionList::TransactionList() : head(nullptr), tail(nullptr)
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
	else
	{
		throw - 1;
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
		if (currentNode->transaction->getEmployeeID() >= newNode->transaction->getEmployeeID())
		{
			if (currentNode->transaction->getEmployeeID() == newNode->transaction->getEmployeeID())
			{
				while (currentNode->priority <= newNode->priority && currentNode->transaction->getEmployeeID() == newNode->transaction->getEmployeeID())
				{
					currentNode = currentNode->next;
				}
			}
			if (currentNode == tail)
			{
				break;
			}
			newNode->next = currentNode;
			newNode->prev = currentNode->prev;
			if (currentNode == head)
			{
				head = newNode;
			}
			else
			{
				currentNode->prev->next = newNode;
			}
			currentNode->prev = newNode;
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