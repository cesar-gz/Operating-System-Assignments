## Assignment 2
Write a C/C++ program to implement an interactive shell in which users can execute commands. Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command. Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments. Consider using the strtok() function. If the command in argument[0] is in the list above, your program must execute the command in a child thread via CreateThread(). In other words, create a child thread that executes the command.  You do not need to actually write code to execute each command.  Simply pass the command into the system call, system() and let the operating system handle the processing for you.  The parent thread waits for the child to terminate. If the user types exit or quit, your shell should simply terminate.


## Assignment 3
Write a C or C++ program to demonstrate thread synchronization.  Your main function should first create a file called synch.txt.  Then it will create two separate threads, Thread-A and Thread-B.  Both threads will open synch.txt and write to it. Thread-A will write the numbers 1 - 26 twenty times in nested for loops then exit. In other words, print 1 - 26 over and over again on separate lines for at least 20 times. Thread-B will write the letters A - Z twenty times in nested for loops then exit.  You must use a mutex lock to control synchronization between the two threads.
