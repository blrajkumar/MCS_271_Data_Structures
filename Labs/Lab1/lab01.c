#define SIZE 50 
#include <ctype.h>
#include <stdio.h>

char stack[SIZE];
int top = -1; 

void RemoveSpaces(char *source)
{
    char *i = source;
    char *j = source;
    while (*j != 0)
    {
        *i = *j++;
        if (*i != ' ')
            i++;
    }
    *i = 0;
}

void push(char exp_char)
{
    stack[++top] = exp_char;
}


char pop()
{
    return (stack[top--]);
}


int priority(char exp_char)
{
    switch (exp_char)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}


void infix_to_postfix(char *infix, char *postfix)
{
    char ch, exp_char;
    int i = 0, k = 0;

    RemoveSpaces(infix);
    push('#');

    while ((ch = infix[i++]) != '\n')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            exp_char = pop(); 
        }
        else
        { 
            while (priority(stack[top]) >= priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#') 
        postfix[k++] = pop();

    postfix[k] = 0;
}


int evaluate_postfix(char *postfix)
{
    char ch;
    int i = 0, op1, op2;
    while ((ch = postfix[i++]) != 0)
    {
        if (isdigit(ch))
            push(ch - '0');
        else
        { 
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
    }
    return stack[top];
}

void main()
{ 

    char infix[50], postfix[50];
    printf("\nInput the infix expression: ");
    fgets(infix, 50, stdin);

    infix_to_postfix(infix, postfix);

    printf("\nGiven Infix Expression: %sPostfix Expression: %s", infix, postfix);
    top = -1;
    printf("\nResult of evaluation of postfix expression : %d\n", evaluate_postfix(postfix));
}