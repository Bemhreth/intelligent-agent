#include <iostream>
#include <string.h>
#include <string>
#include "converter.hpp"
using namespace std;


int top = -1, top1 = -1;
char cont1[100];
char cont2[100];
void push(char num)
{
    top++;
    cont1[top] = num;
}
void push1(char num1)
{
    top1++;
    cont2[top1] = num1;
}
void pop()
{
    cont1[top--];
}
void pop1()
{
    cont2[top1--];
}
typedef char cont[100] ;
char *main_converter(char x[100])
{;
    for (int i = 0; i < strlen(x); i++)
    {
         if (x[i] == '(')
        {
            while (x[i] != ')')
            {
                if (x[i] == '(')
                    push1(x[i]);
                else if(x[i]=='-')
                {
                    if(x[i+1]=='>'){
                        push1(x[i+1]);
                        push1(x[i]);
                        i++;
                    }
                   else
                    {
                        if (x[i] != '>')
                            push(x[i]);
                    }
                }
                else if (x[i] == '<'){
                    push1(x[i+2]);
                    push1(x[i+1]);
                    push1(x[i]);
                    i=+2;
                }
                else if(x[i] =='^'){
                   push1(x[i]);
                }
                else if (x[i] == 'v')
                {
                    push1(x[i]);
                }
                else 
                {
                    if (x[i] != '>')
                        push(x[i]);
                }
                i++;
            }

            while (cont2[top1] != '(')
            {

                if (cont2[top1] != '(')
                {
                    char o = cont2[top1];
                    push(o);
                    pop1();
                }
                else
                    pop1();
            }
            pop1();
        }
        else if (x[i] == '-')
        {
            if (x[i + 1] == '>')
            {
                push1(x[i + 1]);
                push1(x[i]);
                i++;
            }
            else
            {
                push1(x[i]);
            }
        }
        else if (x[i] == '<')
        {
            push1(x[i + 2]);
            push1(x[i + 1]);
            push1(x[i]);
            i = +2;
        }
        else if (x[i] == '^')
        {
            push1(x[i]);
        }
        else if (x[i] == 'v')
        {
            push1(x[i]);
        }
        else
        {
            if (x[i] != '>')
                push(x[i]);
        }
        
    }
    while (top1 != -1)
    {
        if (cont2[top1] != '(')
        {

            char l = cont2[top1];
            push(l);
            pop1();
        }
        else
            pop1();
    }
    return cont1;
}
