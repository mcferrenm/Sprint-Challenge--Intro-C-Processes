**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running - process is currently is use or is ready
Wait - process has called wait() and resumes after child process finishes
Zombie - the process has finished running, but its parent hasn't cleaned it up yet
Orphan - the processes' parent is stopped, and never cleaned up the the child so it continues with the main process adopting it.
Stopped - process is over



**2. What is a zombie process?**

A process that has exited correctly, however there is still a record of it existing.

**3. How does a zombie process get created? How does one get destroyed?**

It gets created when it finishes and its parent is in a waiting state for some reason. It gets destroyed when the parents wait() finishes, and is "reaped" or cleaned up from the record.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Strict typechecking solves a whole class of bugs at compile time. Compiled executuables contain everything they need to run so they are generally faster, where as non complied code needs a runtime program to run the program.

