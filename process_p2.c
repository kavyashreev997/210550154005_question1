//KAVYA SHREE V 210550154005
//Using message queues to recieve the data from process 1 and print the length of the string

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<string.h>

mqd_t dictionarymq;
struct mq_attr dictionarymq_attr;
char buff[128];
int msg_prio;

int main()
{
    dictionarymq_attr.mq_flags=0;
    dictionarymq_attr.mq_maxmsg=4;
    dictionarymq_attr.mq_msgsize=128;

    dictionarymq_attr.mq_curmsgs=0;

    dictionarymq=mq_open("/dictionarymq",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&dictionarymq_attr);
    mq_receive(dictionarymq,buff,128,&msg_prio);
    printf("The message is recieved :%s\nThe msg prior:%d\n",buff,msg_prio);
    printf("Size of message recieved:%s\n",strlen(buff));
    mq_close(dictionarymq);
    return 0;
}
