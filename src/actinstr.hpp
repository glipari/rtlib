/***************************************************************************
    begin                : Wed Jul 30 14:36:51 CEST 2003
    copyright            : (C) 2003 by Cesare Bartolini
    email                : c.bartolini@isti.cnr.it
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef __ACTINSTR_HPP__
#define __ACTINSTR_HPP__

#include <string>
#include <vector>

#include <factory.hpp>
#include <event.hpp>

#include <instr.hpp>

namespace RTSim {

  using namespace std;
  using namespace MetaSim;

  class Task;

  /** 
      \ingroup instr

      Class used when a task must activate another.
      @author Cesare Bartolini
      @see Instr
   */
  class ActInstr : public Instr {
  protected:

    /// Name of the target task.
    string _target;
    /// Event for scheduling the instruction.
    EndInstrEvt _endEvt;

  public:

    /** This is the constructor of the ActInstr.
     *  @param f is a pointer to the task containing the pseudo intruction
     *  @param t is the name of the target task
     *  @param n is the instruction name
     */
    ActInstr(Task* f, const char* t, char* n = "");

    /** Another constructor, where t is a string and not a char array.
     *  @param f is a pointer to the task containing the pseudo intruction
     *  @param t is the name of the target task
     *  @param n is the instruction name
     */
    ActInstr(Task* f, const string& t, char* n = "");

    /** Creates a new instance of the instruction.
     */
    static Instr* createInstance(vector<string>& par);

    /** Virtual method from Instr. Sets the event for this instruction.
     */
    virtual void schedule();

    /** Virtual method from Instr. Drops the event for this instruction.
     */
    virtual void deschedule();

    /** Virtual method from Instr. Useless in this class.
     */
    virtual Tick getExecTime() const { return 0; }

    /** Virtual method from Instr. Useless in this class.
     */
    virtual Tick getDuration() const { return 0; }

    /** Virtual method from Instr. Useless in this class.
     */
    virtual Tick getWCET() const throw(RandomVar::MaxException) { return 0; }

    /** Returns the target of this ActInstr.
     */
    virtual string getTarget() const { return _target; }

    /** Virtual method from Instr. Useless in this class.
     */
    virtual void reset() {}

    /** setTrace
     */
    virtual void setTrace(Trace*);

    /** Actions taken when the instruction is finished. Here is the real
     *  activation.
     */
    virtual void onEnd();

    /** Virtual method from Instr. Useless in this class.
     */
    virtual void newRun() {}

    /** Virtual method from Instr. Removes the event.
     */
    virtual void endRun();
	
    /** Function inherited from clss Instr. It refreshes the state 
     *  of the executing instruction when a change of the CPU speed occurs. 
     */ 
    virtual void refreshExec(double, double) {}
  };

}

#endif
