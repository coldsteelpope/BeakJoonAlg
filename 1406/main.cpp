#include <iostream>

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }


using namespace std;

class CNode
{
public:
	CNode(char _cData) : m_cData(_cData), m_next(nullptr), m_prev(nullptr) {}
	~CNode() {}
public:
	char GetData() { return m_cData; }
	char SetData(char _cData) { m_cData = _cData; }

	CNode* GetNextNode() { return m_next; }
	CNode* GetPrevNode() { return m_prev; }

	void SetNextNode(CNode* _node) { m_next = _node; }
	void SetPrevNode(CNode* _node) { m_prev = _node; }
private:
	char	m_cData;
	CNode*	m_next;
	CNode*	m_prev;
};

class CLinkedList
{
public:
	CLinkedList() : m_iCount(0)
	{
		m_head = new CNode(-1);
		m_tail = new CNode(-1);
		m_Cursor = m_head;

		m_head->SetNextNode(m_tail);
		m_tail->SetPrevNode(m_head);
	}
	~CLinkedList()
	{
		while (IsEmpty() == false)
		{
			PopBack();
		}

		SAFE_DELETE(m_head);
		SAFE_DELETE(m_tail);
	}
public:
	void AddNodeInCursor(CNode* _node)
	{
		m_Cursor->GetNextNode()->SetPrevNode(_node);
		_node->SetNextNode(m_Cursor->GetNextNode());

		_node->SetPrevNode(m_Cursor);
		m_Cursor->SetNextNode(_node);

		m_Cursor = _node;
		++m_iCount;
	}
	
	void DeleteNodeInCursor()
	{
		if (m_Cursor == m_head || m_Cursor == m_tail)
		{
			return;
		}

		CNode* deleteNode = m_Cursor;
		deleteNode->GetNextNode()->SetPrevNode(deleteNode->GetPrevNode());
		deleteNode->GetPrevNode()->SetNextNode(deleteNode->GetNextNode());

		m_Cursor = deleteNode->GetPrevNode();
		SAFE_DELETE(deleteNode);
		--m_iCount;
	}

	bool IsEmpty()
	{
		return m_iCount == 0;
	}

	void PopBack()
	{
		if (m_iCount == 0)
		{
			return;
		}
		CNode* deleteNode = m_tail->GetPrevNode();
		deleteNode->GetNextNode()->SetPrevNode(deleteNode->GetPrevNode());
		deleteNode->GetPrevNode()->SetNextNode(deleteNode->GetNextNode());

		SAFE_DELETE(deleteNode);
		--m_iCount;
	}

	void MoveCursorLeft()
	{
		if (m_Cursor == m_head)
		{
			return;
		}
		m_Cursor = m_Cursor->GetPrevNode();
	}

	void MoveCursorRight()
	{
		if (m_Cursor == m_tail)
		{
			return;
		}
		m_Cursor = m_Cursor->GetNextNode();
	}

public:
	void SetCursor(CNode* _node) { m_Cursor = _node; }

	CNode* GetHead() { return m_head; }
	CNode* GetTail() { return m_tail; }
private:
	int m_iCount;
	CNode* m_Cursor;
	CNode* m_head;
	CNode* m_tail;
};

class CEditor
{
public:
	CEditor()
	{
		m_linkedList = new CLinkedList();
	}

	CEditor(string _str)
	{
		m_linkedList = new CLinkedList();
		for (char ele : _str)
		{
			m_linkedList->AddNodeInCursor(new CNode(ele));
		}
		m_linkedList->SetCursor(m_linkedList->GetTail()->GetPrevNode());
	}

	~CEditor() 
	{
		SAFE_DELETE(m_linkedList);
	}
	
public:
	void L()
	{
		m_linkedList->MoveCursorLeft();
	}

	void D()
	{
		m_linkedList->MoveCursorRight();
	}

	void B()
	{
		m_linkedList->DeleteNodeInCursor();
	}

	void P(char _cData)
	{
		CNode* newNode = new CNode(_cData);
		m_linkedList->AddNodeInCursor(newNode);
	}

	void PrintStr()
	{
		CNode* currentNode = m_linkedList->GetHead()->GetNextNode();
		while (currentNode->GetNextNode() != nullptr)
		{
			cout << currentNode->GetData();
			currentNode = currentNode->GetNextNode();
		}
	}
private:
	CLinkedList* m_linkedList;
};



int main(void)
{
	string prevStr;
	cin >> prevStr;
	CEditor* editor = new CEditor(prevStr);
	
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		char cCommand;
		cin >> cCommand;

		switch (cCommand)
		{
		case 'L':
		{
			editor->L();
		}
			break;
		case 'P':
		{
			char addChar;
			cin >> addChar;
			editor->P(addChar);
		}
			break;
		case 'B':
		{
			editor->B();
		}
			break;
		}
	}
	editor->PrintStr();
	
	SAFE_DELETE(editor);
	return 0;
}