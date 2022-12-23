#include<iostream> 
using namespace std; 
struct node
{
  int data;
  node *next;
};

class Linkedlist
{
public:
  node * head = NULL;
  void insertfront (int val)
  {
    node *newnode = new node;
      newnode->data = val;
    if (head == NULL)
      {
	newnode->next = NULL;
	head = newnode;
      }
    else
      {
	newnode->next = head;
	head = newnode;
      }
  }
  void display ()
  {
    if (head == NULL)
      {
	cout << "The list is empty";
      }
    node *temp = head;
    while (temp != NULL)
      {
	cout << temp->data << endl;
	temp = temp->next;
      }
  }
  void search (int key)
  {
    if (head == NULL)
      {
	cout << "list is empty";
      }
    node *temp = head;
    int c = 0;
    while (temp)
      {
	if (temp->data == key)
	  {
	    c += 1;
	  }
	temp = temp->next;
      }
    if (c >= 1)
      {
	cout << "element found\n";
      }

    else
      cout << "element not found";
  }
  void insert (int pos, int val)
  {
    node *newnode = new node;
    newnode->data = val;
    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
      {
	if (temp == NULL)
	  {
	    cout << "invalid position";
	    break;
	  }
	temp = temp->next;
      }
    newnode->next = temp->next;
    temp->next = newnode;
  }
  void insertend (int val)
  {
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    node *newnode = head;
    newnode = head;
    while (newnode->next != NULL)
      {
	newnode = newnode->next;
      }
    newnode->next = temp;
  }
  void remove (int pos)
  {
    node *temp = head;
    node *prev;
    if (temp == NULL)
      cout << "list is already empty";
    if (pos == 0)
      {
	head = head->next;
	delete temp;
      }
    for (int i = 0; i < pos; i++)
      {
	prev = temp;
	temp = temp->next;
      }

    prev->next = temp->next;
    delete temp;
  }
};

int
main ()
{
  Linkedlist l;
  while (1)
    {
      cout << "1.display" << endl;
      cout << "2.insert" << endl;
      cout << "3.insert at end";
      cout << "4.search" << endl;
      cout << "5.remove" << endl;
      cout << "6.exit" << endl;
      int ch, val, pos, key;
      cout << "enter your choice: ";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  l.display ();
	  break;
	case 2:
	  cout << "enter the position";
	  cin >> pos;
	  cout << "enter the value";
	  cin >> val;
	  if (pos == 0)
	    l.insertfront (val);
	  else
	    {
	      l.insert (pos, val);
	    }
	  break;
	case 3:
	  cout << "Enter the value:";
	  cin >> val;
	  l.insertend (val);
	  break;
	case 4:
	  cout << "enter the key:";
	  cin >> key;
	  l.search (key);
	  break;
	case 5:
	  cout << "enter the position:";
	  cin >> pos;
	  l.remove (key);
	  break;
	case 6:
	  exit (0);
	default:
	  cout << "invalid choice";

	}
    }
}
