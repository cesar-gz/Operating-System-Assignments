## Assignment 2
Write a C/C++ program to implement an interactive shell in which users can execute commands. Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command. Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments. Consider using the strtok() function. If the command in argument[0] is in the list above, your program must execute the command in a child thread via CreateThread(). In other words, create a child thread that executes the command.  You do not need to actually write code to execute each command.  Simply pass the command into the system call, system() and let the operating system handle the processing for you.  The parent thread waits for the child to terminate. If the user types exit or quit, your shell should simply terminate.
