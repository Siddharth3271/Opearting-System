#include<stdio.h>
#include<unistd.h>
int main()
{
    execlp("ls","ls","-l",(char*)NULL);
    perror("execlp"); //this will be execute if execlp fails
    return 0;
}