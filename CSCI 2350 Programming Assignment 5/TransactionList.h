#pragma once
#include "Transaction.h"
using namespace std;

class TransactionList
{
	struct Node
	{
		Transaction* transaction;
		int priority;
		Node* next;
		Node* prev;
	};
private:
	Node* head;
	Node* tail;
public:
	TransactionList();
	~TransactionList();
	Transaction* removeTransaction();
	void addTransaction(Transaction*);
	bool isEmpty();
};