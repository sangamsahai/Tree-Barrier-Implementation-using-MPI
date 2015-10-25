# Tree-Barrier-Implementation-using-MPI (Message Passing Interface)
This is a parallel processing project. This implements the native function 'Barrier' from scratch using MPI.


This uses the concept of Tree Barrier to achieve High degree of parallelism.

Barrier is a mechanism, which is used to synchronize the execution of code running parallel on different nodes.

This application assumes that the total number of nodes will a power of 2 (like 2, 4 , 8 etc.).

The code is written in C.

Please read the file 'Description_And_technique_Used.docx' to read the about the technique and complete Algorithm .

How to Run:-

1)	The command used to compile the code is ->
mpicc –o <executable name><filename>

2)  The command used to run the code is ->
mpirun –np<no of parallel processors><executable name>
