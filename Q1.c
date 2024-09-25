#include<stdio.h>
#include<dirent.h>
int main()
{
    DIR *d;
    d=opendir(".");
    if(d){
        printf("Contents of directory:\n");
        struct dirent *dir;
        while((dir=readdir(d))!=NULL){
            printf("listfiles\n");
        }
    }
    else{
        perror("opendir");
    }
    return 0;
}