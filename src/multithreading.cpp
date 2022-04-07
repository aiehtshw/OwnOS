#include <multithreading.h>
using namespace myos;
using namespace myos::common;

// I copy this constructer IDK...
Thread::Thread(GlobalDescriptorTable *gdt, void entrypoint()){

    cpustate = (CPUState*)(stack + 4096 - sizeof(CPUState));
    
    cpustate -> eax = 0;
    cpustate -> ebx = 0;
    cpustate -> ecx = 0;
    cpustate -> edx = 0;

    cpustate -> esi = 0;
    cpustate -> edi = 0;
    cpustate -> ebp = 0;
    
    cpustate -> eip = (uint32_t)entrypoint;
    cpustate -> cs = gdt->CodeSegmentSelector();
    // cpustate -> ss = ;
    cpustate -> eflags = 0x202;
}

// Finsih Thread
Thread::~Thread(){

}

// For adding thread
bool ThreadManager::AddThread(Thread* thread){
    if(numThread >= 256)
        return false;
    threads[numThread++] = thread;
    return true;
}

// For waiting for the task to finish a thread
bool ThreadManager::JoinThread(Thread*thread){

}

// kill/finish a thread
bool ThreadManager::TerminateThread(Thread*thread){

}

// I do not know now :D
bool YieldingThread(Thread* thread){

}

CPUState* ThreadManager::Schedule(CPUState* cpustate)
{
    if(numThread <= 0)
        return cpustate;
    
    if(currentThread >= 0)
        threads[currentThread]->cpustate = cpustate;
    
    if(++currentThread >= numThread)
        currentThread %= numThread;
    return threads[currentThread]->cpustate;
}

ThreadManager::ThreadManager(){
    numThread = 0;
    currentThread = -1;
}
// Finish thread manager
ThreadManager::~ThreadManager(){

}

