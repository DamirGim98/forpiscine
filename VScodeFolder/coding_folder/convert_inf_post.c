#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define push(sp, n) (*((sp)++) = (n)) && (tops++)
#define pop(sp) (*--(sp)) && (tops--)
#define top(sp) (*(sp - 1))

char * Infix_postfix(char * expression, int n);

bool HigherPrecedence(char top, char element); 

bool IsEmpty(int tops); 

bool IsOperator(char c); 

int main(void)
{
    char expression[50];
    fgets(expression, sizeof(expression), stdin);
    int n = strlen(expression) - 1;
    char * res = Infix_postfix(expression, n);
    for (int i = 0; i < n; i++)
    {
        printf("%c", res[i]);
    }
    return 0;
}

char * Infix_postfix(char * expression, int n)
{
    char * res = (char *)malloc((n+1)*sizeof(char));
    int step = 0;

    char stack[50];
    char * sp = stack;
    int tops = -1;

    for (int i = 0; i < n; i++)
    {
        if (expression[i] >= 'A' && expression[i] <= 'Z')
        {
            res[step] = expression[i];
            step = step + 1;
        } else if (IsOperator(expression[i]))
        {
            // printf("%d\n", !(IsEmpty(tops)) );
            // printf("%d\n", HigherPrecedence(top(sp), expression[i]));
            while (!(IsEmpty(tops)) && HigherPrecedence(top(sp), expression[i]))
            {
                res[step] = top(sp);
                step = step + 1;
                pop(sp);
            }
            push(sp,expression[i]);
            // printf("%c\n", top(sp));
        } 
    }
    while (!(IsEmpty(tops)))
    {
        res[step] = top(sp);
        step = step + 1;
        pop(sp);
    }
    return res;
}

bool IsOperator(char c)
{
    if (c == '*' || c == '/' || c == '-' || c == '+')
    {
        return true;
    }
    return false;
}

bool HigherPrecedence(char top, char element)
{
    bool flag = true; 
    if ((element == '*' || element == '/') && (top == '-' || top == '+'))
    {
        flag = false;
    }
    return flag;
}

bool IsEmpty(int tops)
{
  if (tops == -1) return true;
  return false;
}