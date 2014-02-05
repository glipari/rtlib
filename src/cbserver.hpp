#ifndef __CBSERVER_H__
#define __CBSERVER_H__

#include <server.hpp>
#include <capacitytimer.hpp>
#include <list>

namespace RTSim {

    using namespace MetaSim;

    class CBServer : public Server {
    private:
        Tick Q,P,d;
        Tick cap; 
        Tick last_time;
        Tick recharging_time;
        int HR;
        
        /// replenishment: it is a pair of <t,b>, meaning that
        /// at time t the budget should be replenished by b.
        typedef std::pair<Tick, Tick> repl_t;

        /// queue of replenishments
        /// all times are in the future!
       std::list<repl_t> repl_queue;

        /// at the replenishment time, the replenishment is moved
        /// from the repl_queue to the capacity_queue, so 
        /// all times are in the past.
        std::list<repl_t> capacity_queue;

        /// A new event replenishment, different from the general
        /// "recharging" used in the Server class
        GEvent<CBServer> _replEvt;

        /// when the server becomes idle
        GEvent<CBServer> _idleEvt;

        CapacityTimer vtime;

    public:
      CBServer(Tick q, Tick p, Tick d, bool HR,  const std::string &name, 
                       const std::string &sched = "FIFOSched");

        void newRun();
        void endRun();
      
        virtual Tick getBudget() const { return Q;}
        virtual Tick getPeriod() const { return P;}

        Tick changeBudget(const Tick &n);

        Tick changeQ(const Tick &n);
        virtual Tick getVirtualTime();

    protected:
                
        /// from idle to active contending (new work to do)
        virtual void idle_ready();

        /// from active non contending to active contending (more work)
        virtual void releasing_ready();
                
        /// from active contending to executing (dispatching)
        virtual void ready_executing();

        /// from executing to active contenting (preemption)
        virtual void executing_ready();

        /// from executing to active non contending (no more work)
        virtual void executing_releasing();

        /// from active non contending to idle (no lag)
        virtual void releasing_idle();

        /// from executing to recharging (budget exhausted)
        virtual void executing_recharging();

        /// from recharging to active contending (budget recharged)
        virtual void recharging_ready();

        /// from recharging to active contending (budget recharged)
        virtual void recharging_idle();

        void onReplenishment(Event *e);

        void onIdle(Event *e);

        void prepare_replenishment(const Tick &t);
        
        void check_repl();

    };
}


#endif
