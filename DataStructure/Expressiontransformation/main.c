#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

// 元素退栈
char pop(char *optr, int *_top)
{
    char ch = optr[*_top];
    (*_top)--;
    return ch;
}

// 元素进栈
void push(char *optr, char ch, int *_top)
{
   (*_top)++;
    optr[*_top] = ch;
}

// 获取栈顶元素
char get_top(char *optr, int *_top)
{
    return optr[*_top];
}

// 栈中运算符转化
int ispTransform(char c)
{
    switch(c)
    {
        case '#':return 0;break;
        case '(':return 1;break;
        case '+':return 2;break;
        case '-':return 2;break;
        case '*':return 3;break;
        case '/':return 3;break;
        case ')':return 4;break;
        default: return -1;break;
    }
}

// 栈外运算符转化
int icpTransform(char c)
{
    switch(c)
    {
        case '#':return 0;break;
        case '(':return 4;break;
        case '+':return 2;break;
        case '-':return 2;break;
        case '*':return 3;break;
        case '/':return 3;break;
        case ')':return 1;break;
        default: return -1;break;
    }
}

// 中缀表达式转化为后缀表达式
void exTransform(char *optr, int *_top)
{
    char ch1;
    push(optr, '#', _top);// 先把‘#’压栈
    char ch = getchar();
    while(ch!='#' || get_top(optr,_top)!='#') // 读到结束符或者栈空退出
    {
        // 如果不是运算符就输出
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='(' && ch!=')' && ch!='#')
        {
            putchar(ch);
            ch = getchar(); // 接着读下一位
        }
        else
        {
            // 判断栈内运算符和站外运算符的优先级
            if(ispTransform(get_top(optr,_top)) >= icpTransform(ch))
            {
                // 如果栈内优先级大于或者等于栈外优先级，运算符出栈
                ch1 = pop(optr,_top);
                if(ch1!='(')
                    printf("%c",ch1);
            }
            else{
                if(ch==')')
                    ch = getchar();
                else{
                    push(optr,ch,_top);
                    ch = getchar();
                }
            }
        }
    }
}
int main()
{
    int top = -1;// 栈顶指针
    char optr[MAX_SIZE];// 操作符栈，最大容量MAX_SIZE
    exTransform(optr,&top);
    //printf("Hello world!\n");
    return 0;
}
