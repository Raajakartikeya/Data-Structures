#include<iostream>
using namespace std; 
class stack
{
    public:
    int top,i;
    int stk[50];

stack()
{
    top=-1;
}
void push(int data)
{
    stk[++top]=data;
}
void pop()
{
    cout<<"Deleted:"<<stk[top--];
}
void display()
{
    for(i=top;i>=0;i--)
    {
        cout<<stk[i]<<endl;
    }
}   
};
int main()
{
    stack obj;
    int ch,x;
    cout<<"\nMain Menu\n1.Push\n2.Pop\n3.Display\n4.Exit";
    while(1)
    {
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter the number:";
            cin>>x;
            obj.push(x);
            break;
            case 2:
            obj.pop();
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