#include <string.h>
#include <iostream>
#include "Queue.hpp"

#include "Stack.hpp"
#include "StringFactory.hpp"



using namespace std;

bool isanum(string a){

    if ((a!= "*") && (a!= "/") && (a!="+") && (a!= "-"))

{
        return true;
}
    else{
        return false;
    }
}

int priortizer(string opr)
{
    if(opr == "*")
    {
        return 2;
    }

    else if(opr == "/"){
        return 2;
    }

    else if(opr == "+"){
        return 1;
    }

    else{
        return 1;
    }
}
int main()
{
    string s = "3+4-8*2+2";
    string ops = "+-*/";
    Queue* inputQ = StringFactory::split(s,ops); 
    Queue* outputQ = new Queue(); 
    Stack* opstack = new Stack();

    int myCounter = inputQ->getCount();
    for(int i = 0; i < myCounter; i++)
    {
        string temp = inputQ->dequeue();
        if(isanum(temp))
        {
            outputQ->enqueue(temp);
        }
        else
        {

            if(opstack->getCount() == 0)
            {
                opstack->push(temp);
            }
            else
            {
                while(priortizer(opstack->peek()) > priortizer(temp))
                {
                    outputQ->enqueue(opstack->pop());
                }
                opstack->push(temp);

            }
        }
    }

    int holder = opstack->getCount();
    for(int j = 0; j<holder; j++)
    {
        outputQ->enqueue(opstack->pop());
    } 

    outputQ->display();
   
    
}

 
