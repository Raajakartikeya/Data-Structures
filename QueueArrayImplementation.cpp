#include<iostream>
using namespace std;
class queue
{
    public:
    int top,bottom,que[50],i;
    queue()
    {
        top=bottom=-1;
    }
    void insert(int data)
    {
        if(top>4)
        {
            cout<<"Queue Over Flow";
            return;
        }
        que[++top]=data;
    }
    void delet()
    {
        if(top<0)
        {
            cout<<"Queue Under Flow";
            return;
        }
        cout<<"Deleted:"<<que[++bottom];
    }
    void display()
    {
        if(top==bottom)
        {
            cout<<"\nQueue is Empty";
            return;
        }
        for(i=bottom+1;i<=top;i++)
        {
            cout<<que[i]<<endl;
        }
    }
};
int main()
{
    queue obj;
    int ch,x;
    cout<<"\nMain Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit";
    while(1)
    {
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter the number:";
            cin>>x;
            obj.insert(x);
            break;
            case 2:
            obj.delet();
            break;
            case 3:
            obj.display();
            break;
            case 4:
            exit(0);
            default:
            cout<<"Wrong Choice";
        }
    }
}