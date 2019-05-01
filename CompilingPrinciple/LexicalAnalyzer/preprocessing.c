#include <stdio.h>
#include <stdlib.h>

int chooseSpace(char *buf, int len, char *cur)
{
    /** ����Դ��������Ŀո� */
    int it_buf, it_cur; // buf �� cur �ĵ�����
    it_buf = it_cur = 0;
    while(it_buf<len)
    {
        if(buf[it_buf]!=' ')
        {
            cur[it_cur++] = buf[it_buf++];
        }
        else{
            cur[it_cur++] = buf[it_buf++];
            /* ���������ո�*/
            while(buf[it_buf]==' ')
            {
                it_buf++;
            }
        }
    }
    cur[it_cur] = '\0';
    return it_cur;
}

int chooseComment(char *buf, int len, char *cur)
{
    /** ����Դ���������ע�� */
    int it_buf, it_cur; // buf �� cur �ĵ�����
    it_buf = it_cur = 0;
    while(it_buf<len)
    {
        // �������ע��
        if(buf[it_buf]=='/' && buf[it_buf+1]=='*')
        {
            it_buf++;
            while(1)
            {
                it_buf++;
                if(buf[it_buf]=='*' && buf[it_buf+1]=='/')
                {
                    break;
                }
            }
            it_buf += 2; // buf����������ƶ�����
        }
        // ������ע��
        if(buf[it_buf]=='/' && buf[it_buf+1]=='/')
        {
            while(1)
            {
                it_buf++;
                if(buf[it_buf]=='\n')
                {
                    break;
                }
            }
            it_buf += 1; // buf����������ƶ�һ��
        }
        cur[it_cur++] = buf[it_buf++];
    }
    cur[it_cur] = '\0';
    return it_cur;
}

int chooseControl(char *buf, int len, char *cur)
{
    /** ����Դ����������Ʊ�� */
    int it_buf, it_cur; // buf �� cur �ĵ�����
    it_buf = it_cur = 0;
    while(it_buf<len)
    {
        while(buf[it_buf]=='\r' || buf[it_buf]=='\n' || buf[it_buf]=='\t')
        {
            it_buf++;
        }
        cur[it_cur++] = buf[it_buf++];
    }
    cur[it_cur] = '\0';
    return it_cur;
}

int preprocess(char *buf, int *len, char *cur)
{
    /**char ch = scanf("%c",&ch);
    while(ch!='#')
    {
        buf[len++] = ch;
        ch = scanf("%c",&ch);
    }*/
	printf("please input file name:");
	char file_name[30];
	scanf("%s",file_name);
    FILE *fp = fopen(file_name,"r+");
    if(fp==NULL)
    {
        printf("can not open \"data.txt\".\n");
        exit(0);
    }
    while(fscanf(fp,"%c",&buf[*len])!=EOF)
    {
        (*len)++;
    }
    buf[*len] = '\0';
    fclose(fp);
    printf("%s\n",buf); // Ҫɾ��

    *len = chooseSpace(buf,*len,cur);
    printf("%s\n",cur); // Ҫɾ��
    *len = chooseComment(cur,*len,buf);
    printf("%s\n",buf); // Ҫɾ��
    *len = chooseControl(buf,*len,cur);
    printf("%s\n",cur); // Ҫɾ��
    // �������ַ���������ļ�
    FILE *p;
    if((p=fopen("ProcessAfter.txt","w"))==NULL)
    {
        printf("can not open \"ProcessAfter.txt\".\n");
        exit(0);
    }
    fprintf(p,"%s",cur);
    fclose(p);

    return 0;
}
