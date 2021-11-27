#include <iostream>
using namespace std;

class Node
{

    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
            previous=NULL;
        }
        Node (int k, int d)
        {
            key=k;
            data=d;
        }
};
class DoublyLinkedList
{

    public:
        Node* head;

        DoublyLinkedList()
        {
            head=NULL;
        }
        DoublyLinkedList(Node *n)
        {
            head=n;
        }

        Node* nodeExists(int k)
        {
            Node* temp=NULL;
            Node* ptr=head;

            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->next;
            }

            return temp;
        }

        void appendNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node Appended as Head Node"<<endl;
                }
                else
                {
                    Node* ptr= head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr-> next=n;
                    n->previous = ptr;
                    cout<<"Node Appended"<<endl;
                }
            }
        }

        void prependNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node Prepended as Head Node"<<endl;
                }
                else
                {
                    head->previous=n;
                    n->next=head; 
                    head=n;
                    cout<<"Node Prepended"<<endl;
                }
                
            }
        }

        void InsertNodeAfter(int k, Node *n)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value :"<<k<<endl;
            }
            else
            {
                if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node Already exists with key value : "<<n->key<<". Append another node with difference key value"<<endl;
                }
                else
                {
                    cout<<"INSERTING" <<endl;

                    Node *nextNode = ptr->next;

                    if(nextNode==NULL)
                    {
                        ptr->next=n;
                        n->previous=ptr;
                        cout<<"Node Inserted at the END"<<endl;
                    }
                    else
                    {
                        n->next=nextNode;
                        nextNode->previous=n;
                        n->previous=ptr;
                        ptr->next=n;

                        cout<<"Node Inserted in Between"<<endl;
                    }
                }
            }
        }

        void deleteNodeByKey(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value : "<<k<<endl;
            }
            else
            {
                if(head->key==k)
                {
                    head= head->next;
                    cout<<"Node UNLINKED with key value : "<<k<<endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode =ptr->previous;
                }
                    if(nextNode==NULL)
                    {
                        prevNode->next=NULL;
                        cout<<"Node Delted at the END"<<endl;
                    }
                else
                {
                    prevNode->next=nextNode;
                    nextNode->previous=prevNode;

                    cout<<"Node Deleted in Between" <<endl;
                }
            }
        }
    }

        void updateNodeByKey(int k, int d)
        {

            Node* ptr= nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data Updated Successfully"<<endl;
            }
            else
            {
                cout<<"Node Doesn't exist with key value :"<<k<<endl;
            }
            
        }

        void printlist()
        {
            if(head==NULL)
            {
                cout<<"No Nodes in Doubly Linked List";
            }
            else
            {
                cout<<endl<<"Doubly Linked List Values : ";
                Node* temp=head;

                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") <-->";
                    temp=temp->next;
                }
            }
        }

};
int main()
{

    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do 
    {
        cout<<"\n What operation do you want to perform? Select Option number. Enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. InsertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen()"<<endl;

        cin>>option;
        Node* n1 = new Node();

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Append Node Operation \n Enter key & data of the Node to be Append"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node Operation \n Enter key & data of the Node to be Prepended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.prependNode(n1);
                break;
            case 3:
                cout<<"Insert Node After Operation \n Enter key of existing Node after which you want to Insert this new node"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.InsertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node By Key Operation - \n Enter key of the Node to be deleted:"<<endl;
                cin>>k1;
                obj.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node By Key Operation - \n Enter key & New data to be updated" <<endl;
                cin>>key1;
                cin>>data1;
                obj.updateNodeByKey(k1, data1);
                break;
            case 6:
                obj.printlist();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter Proper Option number"<<endl;
        }

    } 
    while(option!=0)

    return 0;
}
