#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

// Ԫ����ջ
char pop(char *optr, int *_top)
{
    char ch = optr[*_top];
    (*_top)--;
    return ch;
}

// Ԫ�ؽ�ջ
void push(char *optr, char ch, int *_top)
{
   (*_top)++;
    optr[*_top] = ch;
}

// ��ȡջ��Ԫ��
char get_top(char *optr, int *_top)
{
    return optr[*_top];
}

// ջ�������ת��
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

// ջ�������ת��
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

// ��׺���ʽת��Ϊ��׺���ʽ
void exTransform(char *optr, int *_top)
{
    char ch1;
    push(optr, '#', _top);// �Ȱѡ�#��ѹջ
    char ch = getchar();
    while(ch!='#' || get_top(optr,_top)!='#') // ��������������ջ���˳�
    {
        // �����������������
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='(' && ch!=')' && ch!='#')
        {
            putchar(ch);
            ch = getchar(); // ���Ŷ���һλ
        }
        else
        {
            // �ж�ջ���������վ������������ȼ�
            if(ispTransform(get_top(optr,_top)) >= icpTransform(ch))
            {
                // ���ջ�����ȼ����ڻ��ߵ���ջ�����ȼ����������ջ
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
    int top = -1;// ջ��ָ��
    char optr[MAX_SIZE];// ������ջ���������MAX_SIZE
    exTransform(optr,&top);
    //printf("Hello world!\n");
    return 0;
}
