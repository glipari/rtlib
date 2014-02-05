/*
  In this example, a simple system is simulated, consisting of two
  real-time tasks scheduled by RM on a single processor.
*/
#include <kernel.hpp>
#include <rmsched.hpp>
#include <jtrace.hpp>
#include <texttrace.hpp>
#include <rttask.hpp>

using namespace MetaSim;
using namespace RTSim;

int main()
{
    // set the trace file
    JavaTrace jtrace("trace.trc");
    TextTrace ttrace("trace.txt");
  
    // create the scheduler and the kernel
    RMScheduler rmsched;
    RTKernel kern(&rmsched);

    // creates the two tasks. 
    /* t1 has a period of 15, a relative deadline of 15, starts at time 0,
       and is called "taskA" */
    PeriodicTask t1(15, 15, 0, "taskA");
    // Creates the pseudoinstructions for the two tasks
    t1.insertCode("fixed(2);");
    t1.setTrace(&jtrace);

    /* t2 has a period of 20, a relative deadline of 20, starts at time 0,
       and is called "taskB" */
    PeriodicTask t2(20, 20, 0, "taskB"); 
    t2.insertCode("fixed(5);");
    t2.setTrace(&jtrace);

    PeriodicTask t3(25, 25, 0, "taskC"); 
    t3.insertCode("fixed(4);");
    t3.setTrace(&jtrace);

    ttrace.attachToTask(&t1);
    ttrace.attachToTask(&t2);
    ttrace.attachToTask(&t3);

    kern.addTask(t1,"");
    kern.addTask(t2,"");
    kern.addTask(t3,"");

//    kern.setContextSwitchDelay(2);

    try {
        // run the simulation for 500 units of time
        SIMUL.run(500);
    } catch (BaseExc &e) {
        cout << e.what() << endl;
    }
}
