#include<iostream>
#include<conio.h>
using namespace std;
class library
{
    private:
    struct Node
    {
        int id;
        string title,author;
        Node* next_add;
    };
    public:
    Node* head=NULL;
    void menu();
    void add_newbook();
    void search_book();
    void update_book();
    void sort();
    void list_books();
    void delete_book();

};
void library::menu()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n1.Add New Book";
    cout<<"\n\n2.Search A Book";
    cout<<"\n\n3.Update Book";
    cout<<"\n\n4.List All Books";
    cout<<"\n\n5.Delete A Book";
    cout<<"\n\n6.Exit"<<endl;
    cout<<"\n\nEnter Your Choice :";
    cin>>choice;
        switch(choice)
        {
            case 1:
            add_newbook();
            break;
            case 2:
            search_book();
            break;
            case 3:
            update_book();
            break;
            case 4:
            sort();
            list_books();
            break;
            case 5:
            delete_book();
            break;
            case 6:
            exit(0);
            break;
            default:
            cout<<"Enter valid choice..........";
            break;
        }
        getch();
        goto p;


}
void library::add_newbook()
{
    system("cls");
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    Node* newnode=new Node;
    cout<<"\n\nBook Id :";
    cin>>newnode->id;
    cout<<"\n\nBook Title :";
    cin>>newnode->title;
    cout<<"\n\nAuthor :";
    cin>>newnode->author;
    newnode->next_add=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node* ptr=head;
        while(ptr->next_add!=NULL)
        {
           ptr=ptr->next_add;
        }
        ptr->next_add=newnode;
    }
    cout<<"\n\n\t\t\tNew Book Added Successfuly........";
}
void library::search_book()
{
    int t_id,found=0;
    system("cls");
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    if(head==NULL)
    {
        cout<<"\n\nLinked List Is Empty......";
    }
    else
    {
        cout<<"\n\nBook Id : ";
        cin>>t_id;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(t_id==ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n\t\t\t==========Library Managment System============";
                cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n Book Id : "<<ptr->id;
                cout<<"\n\n Title : "<<ptr->title;
                cout<<"\n\n Author : "<<ptr->author;
                found++;
            }
           ptr=ptr->next_add;
        }
        if(found==0)
        {
            cout<<"\n\n Invalid Book Id.........";
        }
    }

}
void library::update_book()
{
    int t_id,found=0;
    system("cls");
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    if(head==NULL)
    {
        cout<<"\n\n Linked List Is Empty.........";
    }
    else
    {
        cout<<"\n\n Book Id : ";
        cin>>t_id;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(t_id==ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n\t\t\t==========Library Managment System============";
                cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n Book Id : ";
                cin>>ptr->id;
                cout<<"\n\n Title : ";
                cin>>ptr->title;
                cout<<"\n\n Author : ";
                cin>>ptr->author;
                found++;
            }
            ptr=ptr->next_add;
        }
        if(found==0)
        {
            cout<<"\n\n Book Id Is Invalid.....";
        }
    }

}
void library::sort()
{
    if(head==NULL)
    {
        system("cls");
        cout<<"\n\n Linked List Is Empty....";
        getch();
        menu();
    }
    int count=0,t_id;
    string t_title,t_author;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next_add;
    }
    for(int i=1;i<count;i++)
    {
        Node* ptr=head;
       for(int j=1;j<count;j++)
       {
           if(ptr->id>ptr->next_add->id)
           {
               //Save data in Temporary Variables
               t_id=ptr->id;
               t_title=ptr->title;
               t_author=ptr->author;
               //Save data in current Node
               ptr->id=ptr->next_add->id;
               ptr->title=ptr->next_add->title;
               ptr->author=ptr->next_add->author;
               //Save data into Next Node
               ptr->next_add->id=t_id;
               ptr->next_add->title=t_title;
               ptr->next_add->author=t_author;
           }
           ptr=ptr->next_add;
       }
    }
}
void library::list_books()
{
    system("cls");
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\n\n Book Id : "<<ptr->id;
        cout<<"\n\n Book Name : "<<ptr->title;
        cout<<"\n\n Author : "<<ptr->author;
        cout<<"\n\n\n ============================================================";
        ptr=ptr->next_add;
    }
}
void library::delete_book()
{
    int t_id,found=0;
    system("cls");
    cout<<"\n\n\t\t\t==============================================";
    cout<<"\n\n\t\t\t==========Library Managment System============";
    cout<<"\n\n\t\t\t==============================================";
    if(head == NULL)
    {
        cout<<"\n\n Linked List Is Empty....";
    }
    else
    {
        cout<<"\n\n Book Id : ";
        cin>>t_id;
        if(t_id==head->id)
        {
            Node* ptr=head;
            head=head->next_add;
            delete ptr;
            cout<<"\n\n Delete book successfully.....";
            found++;
        }
        else
        {
            Node* pre=head;
            Node* ptr=head;
            while(ptr!=NULL)
            {
                if(t_id==ptr->id)
                {
                    pre->next_add=ptr->next_add;
                    delete ptr;
                    cout<<"\n\n Delete Book successfully.....";
                    found++;
                    break;
                }
                pre=ptr;
                ptr=ptr->next_add;
            }
        }
        if(found==0)
        {
            cout<<"\n\n Book Id Is Invalid......";
        }


    }
}
int main()
{
    library obj;
    obj.menu();
}

