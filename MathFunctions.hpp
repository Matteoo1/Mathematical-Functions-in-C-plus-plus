#include<iostream>
#include<stdlib.h>
using namespace std;

template <typename T>
const T pi = T(3.1415926535897932385L);   //template T for pi

bool inPiRange(int k)
{
    bool test=false;
    if(abs(k) < pi<double>) test=true;   // if abs(k) is lower than pi return true
    return test;
}

template <typename T1,typename T2>
bool Greater_than(T1 temp1,T2 temp2) //template function for "greater than"
{
    bool test=false;
    if(temp1>temp2) test=true;       //return true if T1 is greater than T2
    return test;
}

template <typename T>
void Swap_elements(T &temp1 ,T &temp2)     //
{
    T temp=temp1;           // temp to swap between templates
    temp1=temp2;
    temp2=temp;
}

template <typename T>        // to print out the arrays before and after sorting
void Print(T *array,int k)
{   
    cout<<"Array: ";
    for(int i=0;i<k;i++)        //take from 0 to the k number (numbers that we have)
    cout<<array[i]<<" ";  cout<<endl;
}

template <typename T>                      // function to implement bubble sort
void Bubble_Sort(T *array,int k)           //give it an array and how many numbers in it
{
    for(int i=0;i<k-1;i++)
    for(int j=i+1;j<k;j++)
    if(Greater_than(array[i],array[j]))        // compare arrays
    Swap_elements(array[i],array[j]);
}


template <typename T>       //container class of type template
class Container
{
private:

class list             //class list for double linked list, to have the data into it, prev and next
{
    public:
    T data;
    list* prev;
    list* next;

    list()
    {
    prev=NULL;         // set it to mull at first
    next=NULL;
    }
};

public:
list* head;
void Insert(list* next_node, T new_data)                //to inser data,
{
    if (next_node == NULL) {                 //if it's empty make a new node
        list* new_node = new list;
        new_node->data=new_data;
        head=new_node;
        return;
    } 
    list* new_node = new list;               
    new_node->data = new_data;
    new_node->prev = next_node->prev;        //[NULL][new_node][next]  [prev][node1][next]  [prev][node2][next]            
    next_node->prev = new_node;
    new_node->next = next_node;

                                        //[prev][node1][next]  [prev][new_node][next]  [prev][node2][next]
    if (new_node->prev != NULL)        // if new_node->prev not NULL, then the node isn't the first node in the list
    new_node->prev->next = new_node;   // the next of the prev node is the new node
    else
    head = new_node;
}

void Erase(list* pos)
{
if (head == NULL || pos == NULL)       //if the list is empty or the position is not found
return;

if (head == pos)
head = pos->next;                      
if (pos->next != NULL)                  //                              pos
pos->next->prev = pos->prev;            //[prev][node1][next]  [prev][new_node][next]  [prev][node2][next]
//                                      // the prev of the next is the prev of pos
if (pos->prev != NULL)
pos->prev->next = pos->next;
delete(pos);
}

void Print()
{   
list* temp=head;
cout<<"List: ";
while (temp != NULL)         // if temp isn't null then print out the data
{
    cout<<temp->data<<" ";
    temp = temp->next;
}
cout<<endl;
}

friend void Bubble_Sort(Container<T>::list *head)    // friend, to be able to acces Container (it's private)
{                                                                             //for double linked list
    bool test = true;
    Container<double>::list *ptr1;
    Container<T>::list *temp=head;
    if (head == NULL)                            // if it's NULL then the list is empty
        return;
    
    while (test)       //do it as long as test true
    {
        test = false;                           // if it's false then there is nothing to swap
        
            for(ptr1 = temp;ptr1->next != NULL;ptr1=ptr1->next )  
            if (ptr1->data > ptr1->next->data)     //if (a[j]>a[j+1])  // to compare between the node and the next node
            {                                                           
                Swap_elements(ptr1->data, ptr1->next->data);   // if it's so, then swap them //Ascending order
                test = true;        //swaping done
            }
    }
           
}
Container()
{
    head=NULL;        //make it NULL at the begining
}
~Container()              //distructor
{
    delete(head);         //delete memory when work is done
}
}; 

template <typename T>
class Point
{
    public:
    T x;
    T y;

    Point()             // default constrotur
    {
        x=0; 
        y=0;
    }

    Point(T a1,T a2)            // non default constructor
    {
        x=a1;
        y=a2;
    }
};

template <>
void Print< Point<double> >(Point<double> *array,int k)   //to test class point
{
    int i;
    cout<<"Points : ";
    for(i=0;i<k;i++)       //take from 0 to the k number (numbers that we have)
    if(i<k-1)              
    cout<<"("<<array[i].x<<","<<array[i].y<<")"<<" , ";           // (x,y) , (x,y) , .......
    else
    cout<<"("<<array[i].x<<","<<array[i].y<<")"<<endl;    // to print without the " , "
}

template<>              //specialization template to handle point
bool Greater_than< Point<double> , Point<double> >(Point<double> point1, Point<double> point2)
{   
    bool test=false;
    if(point1.y>point2.y) test=true;             //to compare by "y"
    return test;
}
