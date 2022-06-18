#include <stdio.h>
#include <string.h>


#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

int perform_operation(char sign, int a, int b)
{
    int value = 0;
    if (sign == '*') value = a * b;
    if (sign == '+') value = a + b;
    if (sign == '/') value = a / b;
    if (sign == '-') value = a - b;
    return value;
}

int evaluate_postfix(char * exp, int n)
{
    int stack[50] = {0};
    int * sp; 
    sp = stack;
    for (int i = 0; i< n - 1; i++)
    {
        if (exp[i] != '*' && exp[i] != '+' && exp[i] != '/' && exp[i] != '-')
        {
            int x = exp[i] - '0';
            push(sp, x);
        }
        else if (exp[i] == '*' || exp[i] == '+' || exp[i] == '/' || exp[i] == '-')
        {
            int op1 = pop(sp);
            int op2 = pop(sp);
            int res = perform_operation(exp[i], op1, op2);
            push(sp,res);
        }
    }
    return pop(sp);
}

int evaluate_prefix(char * exp, int n)
{
    int stack[50] = {0};
    int * sp; 
    sp = stack;
    for (int i = n - 2; i != -1; i--)
    {
        if (exp[i] != '*' && exp[i] != '+' && exp[i] != '/' && exp[i] != '-')
        {
            int x = exp[i] - '0';
            push(sp, x);
        }
        else if (exp[i] == '*' || exp[i] == '+' || exp[i] == '/' || exp[i] == '-')
        {
            int op1 = pop(sp);
            int op2 = pop(sp);
            int res = perform_operation(exp[i], op1, op2);
            push(sp,res);
        }
    }
    return pop(sp);
}

int main(void)
{
    char exp[20];
    fgets(exp, sizeof(exp), stdin); 
    int n = strlen(exp);
    // int final = evaluate_postfix(exp,n);
    int final = evaluate_prefix(exp,n);
    printf("%d\n", final);
}
