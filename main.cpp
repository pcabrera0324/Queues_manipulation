//
//  main.cpp
//  Queues
//
//  Created by Paul on 11/15/18.
//  Copyright © 2018 Paul. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node* next;
};

typedef node* Creating;

Creating front=NULL;
Creating back=NULL;

bool empty();
void enqueue(int&info);
void pop();
void showtop();
void printStack();
void menu(int&,int&);

int main(int argc, const char * argv[]) {
    
    int option,info;
    menu(option,info);
    
    return 0;
}

bool empty()
{
    if(front==NULL && back==NULL)
    {
        return true;
    } else
        return false;
}

void enqueue(int&info)
{
    Creating thing=new node;
    cout << " Enter value ";
    cin >> info;
    cout << info << " has been inserted" << endl;
    thing->data=info;
    thing->next=NULL;
    
    if(front==NULL)
    {
        front=thing;
        back=thing;
    } else
    {
        back->next=thing;
        back=thing;
    }
    
}

void dequeue()
{
    if (empty()) {
        cout << "Stack is empty";
    } else
    {
        if(front==back)
        {
            cout << front->data << " has been popped " << endl;
            free(front);
            front=back=NULL;
            
        } else
            
        {
            Creating thing=front;
            front=front->next;
            free(thing);
            cout << thing->data << " has been popped " << endl;
        }
    }
}

void showtop()
{
    if(empty())
    {
        cout << "Stack is empty";
    } else
    {
        cout << " Top element is " << front->data << endl;
    }
}


void printStack()
{
    
    if(empty())
    {
        cout << "Stack is empty " << endl;
    } else
    {
        Creating temp=front;
        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp=temp->next;
        }
        cout << "\n";
    }
}

void menu(int&option,int&info)
{
    
    while(option!=5)
    {
        cout << endl;
        cout << "Queues" << endl;
        cout <<"1.enqueue" << endl;
        cout <<"2.dequeue" << endl;
        cout <<"3.Top" << endl;
        cout <<"4.Display" << endl;
        cout <<"5.Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << endl;
                enqueue(info);
                break;
            case 2:
                cout << endl;
                dequeue();
                break;
            case 3:
                cout << endl;
                showtop();
                break;
            case 4:
                cout << endl;
                printStack();
                break;
            case 5:
                option=5;
                break;
                
            default:cout<<"must be between 1-5";
                break;
        }
    }
}
