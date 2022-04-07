#ifndef __MYOS__MULTITHREADING_H
#define __MYOS__MULTITHREADING_H

#include <multitasking.h>
#include <common/types.h>
#include <gdt.h>

namespace myos{

    //I create my thread library like task library
    class Thread {   
        friend class ThreadManager;

        private:
            common::uint8_t stack[4096]; // 4 KiB
            CPUState* cpustate;
        public:
            Thread(GlobalDescriptorTable *gdt, void entrypoint());
            ~Thread();
    };


    class ThreadManager{
   
        private:
            Thread *threads[256];
            int numThread;
            int currentThread;
        public:
            ThreadManager();
            ~ThreadManager();
            // for adding thread
            bool AddThread(Thread* thread);
            // for waiting for the task to finish a thread
            bool JoinThread(Thread*thread);
            // kill/finish a thread
            bool TerminateThread(Thread*thread);
            // I do not know now :D
            bool YieldingThread(Thread* thread);
            
            CPUState* Schedule(CPUState* cpustate);
};

}
#endif