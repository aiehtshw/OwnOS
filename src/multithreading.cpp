#include <multitasking.h>

using namespace myos;
using namespace myos::common;

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
