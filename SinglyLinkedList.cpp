
/* Cpp program implementing singly linked list. Insertion and deletetion at selected position
is implemented in each dedicated function. */

// Just run the code !

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next = NULL;
    }
    
    void insertNode(int data,Node* &head,int position){
        Node* temp = new Node(data);
        Node* dummy;
        if(position == 1){
            temp->next = head;
            head = temp;
        }else{
            int c = 1;
            dummy = head;
            while(dummy->next != NULL){
                c++;
                dummy=dummy->next;
            }
            if(position>c+1){
               cout<<"please enter correct position ( < "<<c+1<<" )"<<endl; 
               return;
            }else{
                dummy->next=temp;
            }
            
        }
    }

    void deleteNode(int position,Node* &head){
        if(position == 1){
            Node* dummy = head->next;
            delete head;
            head = dummy;
        }else{
            if(head->next == NULL){
                delete head;
            }else{
                Node* check = head;
                int c=1;
                while(check != NULL){
                    c++;
                    check=check->next;
                }
                if(position>c+1){
                    cout<<"please enter correct position ( < "<<c+1<<" )"<<endl;
                    return;
                }else{
                    Node* temp = head;
                    position--;
                    while(--position){
                        temp=temp->next;
                    }
                    if(temp->next->next == NULL){
                        delete temp->next;
                        temp->next = NULL;
                    }else{
                        temp->next = temp->next->next;
                    }
                    
                }
                
            }
        }
    }
    
    void print(Node* head){
        if(head == NULL){
            cout<<"Linked List is empty"<<endl;
        }else{
            cout<<"Linked List: ";
            while(head != NULL){
                cout<<head->data<<" ";
                head=head->next;
            }
            cout<<endl;
        }
    }
};

int main()
{

    Node* node1;
    Node* head = node1;
    int choice=1 ;
    while(choice){
        cout<<endl;
        cout<<" --------------------------------------------------------------------------------"<<endl;
        cout<<" --------------------------------------------------------------------------------"<<endl<<endl;
        cout<<"1. Insert a node."<<endl;
        cout<<"2. Delete a node."<<endl;
        cout<<"3. Print the Linked List."<<endl;
        cout<<"0. To exit."<<endl<<endl;
        cout<<"enter corresponding option: ";   
        cin>>choice;
        if(choice == 1){
                int position;
                int data;
                cout<<"enter data and position at which you want to insert: ";
                cin>>data>>position;
                node1->insertNode(data,head,position);
                node1=head;
        }
        else if(choice == 2){
                int position;
                cout<<"enter position of the node to delete: ";
                cin>>position;
                node1->deleteNode(position,head);
                node1=head;
        }else if(choice == 3){
                if(node1 == NULL){
                    cout<<"Linked List is empty"<<endl;
                }else{
                    node1->print(head);                    
                }

        }else if(choice == 0){
            return 0;
        }else{
            cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}
