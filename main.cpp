#include <iostream>
#include<bits/stdc++.h>
using namespace std;
ifstream f("data.in");
ofstream g("data.out");
int A[100];
int array_size;
int connection_number;
int question_number;

void initialise_array(int n);
void print_array_id(void);
void quick_find_union(int a, int b);
bool is_connected (int a, int b);

int main()
{
    //read data
    //read array_size
    f>>array_size;
    //read connection_number
    f>>connection_number;
    //read question_number
    f>>question_number;

    //intialise the array
    initialise_array(array_size);

    //print array id before do quick find union
    print_array_id();

    //connect
    for(int i=1;i<=connection_number;i++)
    {
        int a,b;
        //read 2 points
        f>>a;
        f>>b;
        quick_find_union(a,b);
    }

    //answer
    for(int i=1;i<=question_number;i++)
    {
        int a,b;
        //read 2 points
        f>>a;
        f>>b;
        if (is_connected(a,b)==true) //if 2 points connected
        {
            g<<"TRUE; "; //print out true
        }
        else
        {
            g<<"FALSE; "; //print out false;
        }
    }
    g<<"\n";

    //print array id after do quick find union
    print_array_id();
    return 0;
}

void initialise_array(int n)
{
    for (int i=0;i<n;i++)
    {
        A[i]=i;
    }
}

bool is_connected (int a, int b)
{
    if (A[a]==A[b]) //if id of A[a] equal to id of A[b]
    {
        return true; //return true which shows 2 points are connected
    }
    return false;
}

void quick_find_union(int a, int b)
{
    //if a and b connect then connect them otherwise do nothing
    if (is_connected(a,b)==false)
    {
        //remember the id of A[a]
        int temp=A[a];
        //let id A[a]==id A[b]
        A[a]=A[b];
        //check the whole array, if it connect to A[a] then change their id to id of B
        for(int i=0;i<array_size;i++)
        {
            if (A[i]==temp) //if that point connect to A[a]
            {
                A[i]=A[b]; //change their id to id of b
            }
        }
    }
}

void print_array_id(void)
{
    //print the index
    for(int i=0;i<array_size;i++)
    {
        g<<i;
        g<<"  ";
    }
    g<<"\n";
    //print the id
    for(int i=0;i<array_size;i++)
    {
        g<<A[i];
        g<<"  ";

    }
    g<<"\n";
}

