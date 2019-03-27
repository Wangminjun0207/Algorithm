#ifndef _PREDEFINE_H
#define _PREDEFINE_H 1

// **********操作符处理函数***********
// 操作符元素退栈
char pop(char *optr, int *_top)
{
    char ch = optr[*_top];
    (*_top)--;
    return ch;
}

// 操作符元素进栈
void push(char *optr, char ch, int *_top)
{
   (*_top)++;
    optr[*_top] = ch;
}

// 获取操作符栈顶元素
char get_top(char *optr, int *_top)
{
    return optr[*_top];
}
// **********操作符处理函数***********

// **********操作数处理函数***********
// 操作数元素退栈
int pop_number(int *opnd, int *top)
{
    int number = opnd[*top];
    (*top)--;
    return number;
}

// 操作数元素进栈
void push_number(int *opnd, int number, int *top)
{
   (*top)++;
    opnd[*top] = number;
}

// 获取操作数栈顶元素
int get_top_number(int *opnd, int *top)
{
    return opnd[*top];
}
// **********操作数处理函数***********


// 栈中运算符优先级转化
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

// 计算二元运算数值
int calculate(int *opnd,int *top,char ch)
{
    char result;
    int number1 = pop_number(opnd,top);
    int number2 = pop_number(opnd,top);
    switch(ch)
    {
        case '+':result = number2 + number1;break;
        case '-':result = number2 - number1;break;
        case '*':result = number2 * number1;break;
        case '/':result = number2 / number1;break;
        default:break;
    }
    return result;
}
// 栈外运算符优先级转化
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

// 中缀表达式转化为后缀表达式再求值
void exTransform(char *optr,int *opnd, int *_top, int *top)
{
    char ch1;
	int temp;
    push(optr, '#', _top);                    // 先把‘#’压栈
    char ch = getchar();
    while(get_top(optr,_top)!='#' || ch!='#') // 读到结束符或者栈空退出
    {
        // 如果不是运算符就进操作数栈
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='(' && ch!=')' && ch!='#')
        {
			temp = ch - '0';
            push_number(opnd,temp,top);
            ch = getchar();                  // 入栈之后接着读下一位
        }
        else
        {
            // 判断栈内运算符和站外运算符的优先级
            if(ispTransform(get_top(optr,_top)) >= icpTransform(ch))
            {
                // 如果栈内优先级大于或者等于栈外优先级，运算符出栈
                ch1 = pop(optr,_top);
                if(ch1!='(')
				{
					temp = calculate(opnd,top,ch1);
					push_number(opnd, temp, top);
				}
				else
					ch = getchar();
            }
            else{
					push(optr,ch,_top);
                    ch = getchar();
                }
        }
    }
}
#endif // _PREDEFINE_H
