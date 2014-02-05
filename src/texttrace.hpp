/***************************************************************************
    begin                : Thu Apr 24 15:54:58 CEST 2003
    copyright            : (C) 2003 by Giuseppe Lipari
    email                : lipari@sssup.it
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef __TEXTTRACE_HPP__
#define __TEXTTRACE_HPP__

#include <fstream>
#include <iostream>
#include <string>
 
#include <baseexc.hpp>
#include <basetype.hpp>
#include <event.hpp>
#include <particle.hpp>
#include <trace.hpp>

#include <rttask.hpp>
#include <taskevt.hpp>

namespace RTSim {
        using namespace std;
        using namespace MetaSim;

        class TextTrace {
        protected:
                ofstream fd;
        public:
                TextTrace(const string& name) {fd.open(name.c_str());}

                ~TextTrace() {fd.close();}

                void probe(ArrEvt& e)
                {
                        Task* tt = e.getTask();
                        fd << "[Time:" << SIMUL.getTime() << "]\t";  
                        fd << tt->getName() << " arrived at " 
                           << tt->getArrival() << endl;                
                }

                void probe(EndEvt& e)
                {
                        Task* tt = e.getTask();
                        fd << "[Time:" << SIMUL.getTime() << "]\t";  
                        fd << tt->getName()<<" ended, its arrival was " 
                           << tt->getArrival() << endl;
                }

                void probe(SchedEvt& e)
                {
                        Task* tt = e.getTask();
                        fd << "[Time:" << SIMUL.getTime() << "]\t";  
                        fd << tt->getName()<<" scheduled its arrival was " 
                           << tt->getArrival() << endl; 
                }

                void probe(DeschedEvt& e)
                {
                        Task* tt = e.getTask();
                        fd << "[Time:" << SIMUL.getTime() << "]\t";  
                        fd << tt->getName()<<" descheduled its arrival was " 
                           << tt->getArrival() << endl;
                }

                void probe(DeadEvt& e)
                {
                        Task* tt = e.getTask();
                        fd << "[Time:" << SIMUL.getTime() << "]\t";  
                        fd << tt->getName()<<" missed its arrival was " 
                           << tt->getArrival() << endl;
                }

                void attachToTask(Task* t)
                {
                        new Particle<ArrEvt, TextTrace>(&t->arrEvt, this);
                        new Particle<EndEvt, TextTrace>(&t->endEvt, this);
                        new Particle<SchedEvt, TextTrace>(&t->schedEvt, this);
                        new Particle<DeschedEvt, TextTrace>(&t->deschedEvt, this);
                        new Particle<DeadEvt, TextTrace>(&t->deadEvt, this);
                }

        };

}

#endif 
