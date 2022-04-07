#ifndef __MYOS__MULTITHREADING_H
#define __MYOS__MULTITHREADING_H

#include <multitasking.h>


namespace myos{


    class Thread {   
        friend class ThreadManager;
        public:

            Thread();
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
            bool AddThread(Thread* task);
            CPUState* Schedule(CPUState* cpustate);
};

}
#endif