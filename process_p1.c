//KAVYA SHREE V 210550154005
//ALGORITHM
//Create a path file/Usr/share/dictionary
//By using open message queues
//sending the string starting with 'm' to process p2


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t dictionarymq;
struct mq_attr dictionarymq_attr;

int main()
{
 dictionarymq_attr.mq_flags=0;
 dictionarymq_attr.mq_maxmsg=4;
 dictionarymq_attr.mq_msgsize=128;

    dictionarymq=mq_open("/dictionarymq",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR, dictionarymq_attr);
    mq_send(dictionarymq,"m\n",2,0);
    mq_close(dictionarymq);
    return 0;
}