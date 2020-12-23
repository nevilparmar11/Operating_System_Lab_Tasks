#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
void function(char *name)
{
        struct dirent *temp;
        DIR *t;
        if((t=opendir(name))==NULL)
                exit(0);
        strcat(name,"/");
        char n[256];
        strcat(n,name);
        while((temp=readdir(t)))
        {                                                                                                                                                                                                                          if((strcmp((temp->d_name),".")==0) || (strcmp((temp->d_name),"..")==0))
                        continue;
                else                                                                                                                                                                                                                       printf("%s  ",temp->d_name);
        }
        t=opendir(name);
        while((temp=readdir(t)))
        {
                if(strcmp((temp->d_name),".")==0)
                {
                        continue;
                }
                else if(strcmp((temp->d_name),"..")==0)
                {
                        continue;
                }
                else
                {
                        if((temp->d_type)==DT_DIR)
                        {
                                printf("%s",temp->d_name);
                                printf("/");
                                strcpy(n,name);
                                strcat(n,temp->d_name);
                                function(n);
                                printf("\n");
                        }
                }
        }
        printf("\n");
        closedir(t);
}
int main(int argc,int argv[])
{
        char buf[256],temp[256];
        struct dirent *dp;
        DIR *dirp;
        printf("Enter directory path:\n");
        scanf("%s",buf);
        if((dirp=opendir(buf))==NULL)
        {
                printf("Error");
                exit(1);
        }
        strcat(buf,"/");
        strcpy(temp,buf);
        while((dp=readdir(dirp)))
        {
                if((strcmp((dp->d_name),".")==0) || (strcmp((dp->d_name),"..")==0))
                        continue;
                else
                        printf("%s  ",dp->d_name);
        }
        dirp=opendir(buf);
        while((dp=readdir(dirp)))
        {
                if((strcmp((dp->d_name),".")==0) || (strcmp((dp->d_name),"..")==0))
                {
                        continue;
                }
                else
                {
                        if((dp->d_type)==DT_DIR)
                        {
                                printf("%s",dp->d_name);
                                printf(":");
                                strcpy(temp,buf);
                                strcat(temp,(dp->d_name));
                                function(temp);
                        }
                }
                printf("\n");

        }
        closedir(dirp);
}
                                                                        