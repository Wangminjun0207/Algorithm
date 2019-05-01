#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 60
int analysis(char *buf, int *len)
{
    char syn[COUNT][15] = {"include","auto","double","int","struct",
                      "break","else","long","switch","case",
                      "enum","register","typedef","char","extern",
                      "return","union","const","float","short",
                      "unsigned","continue","for","signed","void",
                      "default","goto","sizeof","volatile","do",
                      "while","static","if","+","-",
                      "*","/",":",";","ID",
                      "NUM","(",")","=","<",
                      "==","<=",">=",">","main",
                      "!=","!","->",".","#",
                      "%","[","]","{","}"};
    char Token[*len][30]; // 存储单词
    char sty[30]; // 存储临时单词
    char *p, *q;
    FILE  *fp = fopen("target_file.txt","w");
    if(fp==NULL)
    {
        printf("can not open \"target_file\".\n");
        exit(0);
    }
    p = buf;
    int it_i = 0; // Token迭代器
    int it_m = 0; // syn迭代器
    int flag1 = 1, flag2 = 1; // 用作标识
    //printf("words          key_word       code \n");
    fprintf(fp,"words          key_word       code \n");
    while(*p!='\0')
    {
        /** 单词处理*/
        if((*p>='a'&&*p<='z') || (*p>='A'&&*p<='Z') || (*p=='_'))
        {
            q = sty;
            while((*p>='a'&&*p<='z') || (*p>='A'&&*p<='Z') || (*p=='_') || (*p>='0' && *p<='9'))
            {
                *q = *p;
                p++;
                q++;
            }
            *q = '\0'; // 特别要注意最后的结束符
            strcpy(Token[it_i],sty);
            // 与关键字表进行比对
            for(it_m=0;it_m<COUNT;it_m++)
            {
                if(strcmp(syn[it_m],Token[it_i])==0)
                {
                    break;
                }
            }
            // 输出关键字
            if(it_m<COUNT)
            {
                //printf("%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
                fprintf(fp,"%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
            }
            else
            {
                //printf("%-15s%-15s%-15s\n",Token[it_i],"ID","39");
                fprintf(fp,"%-15s%-15s%-15s\n",Token[it_i],"ID","39");
            }
            it_i++;
            continue;
        }


        /** 数字处理*/
        if(*p>='0' && *p<='9')
        {
            q = sty;
            while((*p>='0' && *p<='9') || ((*p=='.') || (*p=='e') || (*p=='E')))
            {
                if(!flag1 && (*p=='.'))
                {
                    break;
                }
                if(flag1 && (*p=='.'))
                {
                    flag1 = 0;
                }
                if(((*p=='e') || (*p=='E')) && !flag2)
                {
                   break;
                }
                if(((*p=='e') || (*p=='E')) && flag2)
                {
                    flag2 = 0;
                }
                *q = *p;
                p++;
                q++;
            }
            *q = '\0';
            strcpy(Token[it_i],sty);
            //printf("%-15s%-15s%-15s\n",Token[it_i],"NUM","40");
            fprintf(fp,"%-15s%-15s%-15s\n",Token[it_i],"NUM","40");
            it_i++;
            flag1 = flag2 = 1; // 重置标识变量
            continue;
        }

        /** 有可能为双字节的符号处理*/
        if(*p=='!' || *p=='=' || *p=='<' || *p=='>' || *p=='-')
        {
            q = sty;
            *q = *p;
            p++;
            q++;
            while(*p=='=' || *p=='<' || *p=='>' || *p=='>')
            {
                *q = *p;
                p++;
                q++;
            }
            *q = '\0';
            strcpy(Token[it_i],sty);
            // 与关键字表进行比对
            for(it_m=0;it_m<COUNT;it_m++)
            {
                if(strcmp(syn[it_m],Token[it_i])==0)
                {
                    break;
                }
            }
            // 输出关键字
            if(it_m<COUNT)
            {
                //printf("%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
                fprintf(fp,"%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
            }
            it_i++;
            continue;
        }

        /** 其他符号处理*/
        if(*p=='+' || *p=='*' || *p=='/' || *p==':' || *p==';' || *p=='(' ||
           *p==')' || *p=='.' || *p=='#' || *p=='['|| *p==']'|| *p=='{'|| *p=='}'|| *p=='%')
        {
            q = sty;
            *q = *p;
            p++;
            q++;
            *q = '\0';
            strcpy(Token[it_i],sty);
            // 与关键字表进行比对
            for(it_m=0;it_m<COUNT;it_m++)
            {
                if(strcmp(syn[it_m],Token[it_i])==0)
                {
                    break;
                }
            }
            // 输出关键字
            if(it_m<COUNT)
            {
                //printf("%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
                fprintf(fp,"%-15s%-15s%-15d\n",Token[it_i],syn[it_m],it_m);
            }
            it_i++;
            continue;
        }
        p++;
    }
    return 0;
}
