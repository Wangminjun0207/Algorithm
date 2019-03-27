#ifndef _PREDEFINE_H
#define _PREDEFINE_H 1

// **********������������***********
// ������Ԫ����ջ
char pop(char *optr, int *_top)
{
    char ch = optr[*_top];
    (*_top)--;
    return ch;
}

// ������Ԫ�ؽ�ջ
void push(char *optr, char ch, int *_top)
{
   (*_top)++;
    optr[*_top] = ch;
}

// ��ȡ������ջ��Ԫ��
char get_top(char *optr, int *_top)
{
    return optr[*_top];
}
// **********������������***********

// **********������������***********
// ������Ԫ����ջ
int pop_number(int *opnd, int *top)
{
    int number = opnd[*top];
    (*top)--;
    return number;
}

// ������Ԫ�ؽ�ջ
void push_number(int *opnd, int number, int *top)
{
   (*top)++;
    opnd[*top] = number;
}

// ��ȡ������ջ��Ԫ��
int get_top_number(int *opnd, int *top)
{
    return opnd[*top];
}
// **********������������***********


// ջ����������ȼ�ת��
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

// �����Ԫ������ֵ
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
// ջ����������ȼ�ת��
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

// ��׺���ʽת��Ϊ��׺���ʽ����ֵ
void exTransform(char *optr,int *opnd, int *_top, int *top)
{
    char ch1;
	int temp;
    push(optr, '#', _top);                    // �Ȱѡ�#��ѹջ
    char ch = getchar();
    while(get_top(optr,_top)!='#' || ch!='#') // ��������������ջ���˳�
    {
        // �������������ͽ�������ջ
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='(' && ch!=')' && ch!='#')
        {
			temp = ch - '0';
            push_number(opnd,temp,top);
            ch = getchar();                  // ��ջ֮����Ŷ���һλ
        }
        else
        {
            // �ж�ջ���������վ������������ȼ�
            if(ispTransform(get_top(optr,_top)) >= icpTransform(ch))
            {
                // ���ջ�����ȼ����ڻ��ߵ���ջ�����ȼ����������ջ
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
