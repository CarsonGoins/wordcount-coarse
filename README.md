# wordcount-coarse
ITCS-3145 Parallel computing
Answer to question at:

The slowdown occurs with additional threads because more is being asked of the CPU. We can have a look at Amdahl's law since we are parralel computing.
Amdahls law states that "there is always a percentage that can not be run in parallel (the sequential portion) and there is another percentage that can be run in parallel (the parallel portion)".
Thus the CPU is bouncing from parallel and sequential running threads.