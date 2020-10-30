#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    char ss[11111],a[111];
    int cnt=0,now_len=0;
    while(cin>>a)
    {
        if(!strcmp(a,"<br>"))
        {
            ss[cnt++]='\n';

            now_len=0;
            continue;
        }
        if(!strcmp(a,"<hr>"))
        {
           if(now_len)
                ss[cnt++]='\n';
            for(int i=0; i<80; i++)
                ss[cnt++]='-';
            ss[cnt++]='\n';
            now_len=0;
            continue;
        }
        int len=strlen(a);
        if(len+now_len+1>80)       
        {
            ss[cnt++]='\n';
           for(int i=0; i<len; i++)
                ss[cnt++]=a[i];
            now_len=len;
        }
        else
        {
            if(now_len)
                ss[cnt++]=' ';
            for(int i=0; i<len; i++)
                ss[cnt++]=a[i];
            now_len+=len+1;
        }
    }
    ss[cnt]='\0';
    cout<<ss<<endl;
    return 0;

}

