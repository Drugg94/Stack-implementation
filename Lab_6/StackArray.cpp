//Derek Ruggirello



template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) {
			if (temp == top) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

}

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
	int maxSize = maxNumber;
	top = new StackNode(0, nullptr);
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other) 
{
	operator=(other);
}

template <typename DataType>
StackLinked<DataType>::~StackLinked() 
{
	clear();
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other) 
{

	if (this != &other) {
		clear();
		top = new StackNode(other.top->dataItem, 0);
		
		StackNode* thisTemp, * thisPrevious = top;
		while (thisTemp->next != nullptr) {
			thisTemp = other.top->next;
			top = new StackNode(thisTemp->dataItem, thisPrevious);
			thisPrevious = top;
		}
	}

	return *this;
}


template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error) 
{
	if (isFull())
		throw logic_error("List is full. Pop items if new ones are still needed.\n");

	StackNode* tempPtr = top;

	top = new StackNode(newDataItem, tempPtr);
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error) 
{
	if (isEmpty())
		throw logic_error("Trying to pop item in empty list\n");

	StackNode* tempPtr = top;
	DataType tempData = tempPtr->dataItem;
	top = top->next;
	delete tempPtr;
	return tempData;
}

template <typename DataType>
void StackLinked<DataType>::clear() 
{
	delete top;
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const 
{
	if (top == NULL)
		return true;
	else
		return false;
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const 
{
	StackNode* tempPtr = top;

	int count = 0;

	while (tempPtr->next != NULL) {
		count++;
		tempPtr = tempPtr->next;
	}

	if (count >= 8)
		return true;
	else
		return false;
}