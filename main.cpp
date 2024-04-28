#include<iostream>
#include"file.hpp"



int main()
{
cout<<" >>> Exercise 1:"<<endl;
int k=1;
if(inPiRange(k)) cout<<"(k="<<k<<") is smaller than Pi"<<endl;    //test and display the result
else cout<<"(k="<<k<<") is not smaller than Pi"<<endl;
cout<<endl;

cout<<" >>> Exercise 2.1:"<<endl;
if(Greater_than(2,3)) cout<<"2 is greater than 3"<<endl;        // compare the numbers and display result
else cout<<"2 is not greater than 3"<<endl;
if(Greater_than(2.2,3.7)) cout<<"2.2 is greater than 3.7"<<endl;
else cout<<"2.2 is not greater than 3.7"<<endl;
if(Greater_than(2.2,2)) cout<<"2.2 is greater than 2"<<endl;
else cout<<"2.2 is not greater than 2"<<endl;
if(Greater_than(2,2.2)) cout<<"2 is greater than 2.2"<<endl;
else cout<<"2 is not greater than 2.2"<<endl;
cout<<endl;

cout<<" >>> Exercise 2.2 and Exercise 2.3:"<<endl;
double array[9]={2.1,7.4,3,2,1.5,12,5.7,1,15};

Print(array,9);                  // to print out arra before sorting
Bubble_Sort(array,9);            // sort it, use tje bubble_sort function
cout<<"After sort:"<<endl;
Print(array,9);                  //display after sorting
cout<<endl;

cout<<" >>> Exercise 3:"<<endl;
Container <double>x1;
x1.Insert(x1.head, 1.5);                               //1.5
x1.Insert(x1.head, 3.2);                               //3.2 1.5
x1.Insert(x1.head->next, 2);                           //3.2 2 1.5
x1.Insert(x1.head, 5.12);                              //5.12 3.2 2 1.5
x1.Insert(x1.head->next->next, 11.8);                  //5.12 3.2 11.8 2 1.5
x1.Insert(x1.head->next->next->next, 4.88);            //5.12 3.2 11.8 4.88 2 1.5
x1.Insert(x1.head->next, 20);                          //5.12 20 3.2 11.8 4.88 2 1.5
x1.Print();
cout<<"After delete:"<<endl;
x1.Erase(x1.head->next->next);
x1.Erase(x1.head);
x1.Print();
cout<<endl;

cout<<" >>> Exercise 4:"<<endl;
Point<double> pt[6]={{17.4,30.2},{10,21},{15,8},{12,3.5},{7,1.6},{8,5.9}};   //arrays values will be 6 objects
Print(pt,6);                                                                 // display it before sorting
Bubble_Sort(pt,6);                                                           //sort it
cout<<"After sort:"<<endl;                                                  
Print(pt,6);                                                                //print after sorting
cout<<endl;

cout<<" >>> Exercise 5:"<<endl;
x1.Print();                                                                 // display it before sorting
Bubble_Sort(x1.head);                                                       //sort it
cout<<"After sorting:"<<endl;                                               
x1.Print();                                                                 //print after sorting

return 0;
}
