#include <iostream>
#include <unistd.h>
int main()
{
    std::cout<<"Current process Id : "<<getpid()<<std::endl;
    pid_t childProcessId = Fork();
    if(childProcessId < 0)
    {
        std::cout<<"Failed to Create a new Process"<<std::endl;
    }
    else if (childProcessId == 0)
    {
        std::cout<<"Child Process Id : "<<getpid()<< " Its parent ID : "<<getppid()<<std::endl;
    }
    else if (childProcessId > 0)
    {
        std::cout<<"Parent Process Id : "<<getpid()<< " Its Child Process ID : "<<childProcessId<<std::endl;
    }
}
