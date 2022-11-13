## Assignment 1
Was just a simple turn in a hello world file into a auto grader. Not worth adding to GitHub
## Assignment 2
Write a C/C++ program to implement an interactive shell in which users can execute commands. Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command. Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments. Consider using the strtok() function. If the command in argument[0] is in the list above, your program must execute the command in a child thread via CreateThread(). In other words, create a child thread that executes the command.  You do not need to actually write code to execute each command.  Simply pass the command into the system call, system() and let the operating system handle the processing for you.  The parent thread waits for the child to terminate. If the user types exit or quit, your shell should simply terminate.


## Assignment 3
Write a C or C++ program to demonstrate thread synchronization.  Your main function should first create a file called synch.txt.  Then it will create two separate threads, Thread-A and Thread-B.  Both threads will open synch.txt and write to it. Thread-A will write the numbers 1 - 26 twenty times in nested for loops then exit. In other words, print 1 - 26 over and over again on separate lines for at least 20 times. Thread-B will write the letters A - Z twenty times in nested for loops then exit.  You must use a mutex lock to control synchronization between the two threads.

## Assignment 4
For this assignment you will be asked to create a chat application.  For full credit you may implement it as a console application. The application will consist of the following elements: 
1)	A transmit socket for sending chat messages to a specified endpoint, 
2)	A receive socket for receiving chat messages

At the most basic level, the application will allow a user to enter chat messages (either on the command line or into an edit box) and send them to another process on the same computer, simulating a chat application over the Internet

Requirements and Specification
1.	Messages shall be transmitted using a User Datagram Protocol/Internet Protocol (UDP/IP) Socket.  Use the following link for explanation and examples of how to use socket functions in a Windows environment:

The socket functions you will need to use are socket(), sendto(), bind() and closesocket().  However, as you now know, there are multiple libraries that abstract these calls to make it “easier” to implement.  You will need to use a single socket for sending, and a second socket for receiving. Use IP address 127.0.0.1 and port 3514 (CS351-Section 4) to address the other process.  For the receive socket, you must receive on, or bind() to a different port - 3515.  You will use the function recvfrom(), which is a blocking call (i.e. it waits for I/O).  Since you will likely want to send one or more messages while waiting for a message to be received, this function must be performed in a separate Thread. 

2.	When the user enters a chat message and presses return (or a Send button in a GUI), the message shall be sent to the addressee.

With the receive socket, upon receiving a Chat Message, your application shall write the received message to the console.

3.	I will provide a companion application (Chat App (Oates).exe) that will allow you to test yours.  It will show Chat Messages in the Receive Messages window.  Also, it will allow you to send Chat Messages to your application (addressed to port 3515) to test your receive socket.