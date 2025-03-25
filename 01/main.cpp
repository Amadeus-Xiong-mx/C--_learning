#include<iostream>

using namespace std;

struct Point
{
    int data;
    Point *next;
};

struct Qnode
{
    Point* front;
    Point* rear;
};

void init_que(Qnode &Q)
{
    Q.front = Q.rear = new Point;
    Q.front->next=NULL;
}

void insert(Qnode &Q,int dat)
{
    Point *p = new Point;
    p->data=dat;
    Q.rear->next=p;
    p->next=NULL;
    Q.rear=p;
}

int depoint(Qnode &Q,int &ret_dat)
{
    if(Q.front==Q.rear) return 0;
    Point *temp;
    temp=Q.front->next;
    ret_dat=temp->data;
    Q.front->next=temp->next;
    if(temp==Q.rear) Q.rear = Q.front;
    delete temp;
    return 1;
}

int display(Qnode &Q)
{
    if(Q.front!=Q.rear)
    return Q.front->next->data;
}

int main(void)
{
    Qnode Q;
    int ret_dat;
    char com;
    int dat;
    init_que(Q);
    while(1)
    {
        cin>>com;
        switch(com)
        {
            case 'i':
            cin>>dat;
            insert(Q,dat);
            cout<<"success to insert"<<endl;
            break;
            case 'd':
            if(depoint(Q,ret_dat))
            cout<<ret_dat<<endl<<"succes to delete"<<endl;
            else
            cout<<"error"<<endl;
            break;
            case 'p':
            cout<<display(Q)<<endl;
            break;   
        }
    }
}