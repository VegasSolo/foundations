// linkedlist.h
struct Node
{
	Node(char sym, int val, Node *nxt = NULL);
	float value;
	Node *next;
	char symbol;
};


LL.find('A'); // return node that has symbol == to pass


// ************************************** \\
// linkedlist.h
virtual int &get(char symb);
virtual void set(char symb, int x);

virtual void insert(int i, char symb, int x);
virtual void append (char symb, int x);
virtual void remove (char symb);


// linkedlist.cpp
Node::Node(char sym, int val, Node *nxt)
{
	symbol = sym;
	value = val;
	next = nxt;
}

// in copy construtor
head = new Node(other.head->symbol, other.head->value);


// in get method
while (n != NULL && n->symbol != symb)
{
}
if (n==NULL)
{
	cout << "there is no " << symbol << "!" << endl; 
	/*
	in set method, if it couldn't find it, then 
	append(symbol, x);
	instead of error message.
	*/
	return -1;
}
else
{
	return n->value;
}



// remove
{
	size--;
	
	Node *n = head;
	int i = 0;
	while (n->symbol != symbol)
	{
		n = n->next;
		i++;
	}
	
	//
	
}


// extra credit for exponents ( A = 2 3 ^ ) would save 2^3 in A


// stack notes
// pattern matching using parenthesis
// example:   ((()))
for (int i = 0; i < str.length(); i++)
{
	if "(" : push
	else if ")" : match
}
if stack == empty
	return true;
else 
	return false;



// reading it
string s;
cin >> s;
if (s[0] >= '0' && s[0] <= '9')
{
	int num = atoi(s.c_str);
	//
}