#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>
using namespace std;

// ConsoleApplication1.cpp : Simple Command Line Interpreter.
// Copyright (c) Cesar Gutierrez 9/24/2022
//

DWORD WINAPI commandCaller(LPVOID userInput){

    char *command;
    command = (char*)userInput;
    cout << "" << endl;
    system(command);
    return 0;
}

int myShell(){

    string userInput;
    string commands[] = {"dir", "help", "vol", "path", "tasklist", "notepad", 
                         "echo", "color", "ping", "ls", "pwd", "ps", "gedit"};
    cout << "\nEnter your command and I shall make it so ->";
    getline (cin, userInput);
    
    if(userInput == "quit" || userInput == "exit"){
        // exit program
        return 1;
    }
    else{
        /* 
            used https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
            to help break down userInput string into tokens            
        */
        vector <string> tokens;
        stringstream check1(userInput);
        string intermediate;
        while(getline(check1, intermediate, ' ')){
            tokens.push_back(intermediate);
        }

        // compare the command against the list of supported commands
        for(int i=0; i<size(commands); i++){
            if(tokens[0] == commands[i]){

                //create a child thread
                HANDLE handleThread;
                DWORD thread;
                handleThread = CreateThread(
                    NULL,                           // default security attribute
                    0,                              // default 1MB size
                    commandCaller,                  // function address to be called
                    (void*)userInput.c_str(),       // function parameter to pass, takes pointer
                    0,                              // creation flag
                    &thread                         // address of thread
                );
                WaitForSingleObject(handleThread, INFINITE);
                CloseHandle(handleThread);
                break;
            }
        }

        return 0;
    }
}

int main(){

    cout << "\nWelcome to myShell.\n";

    while(1){
        
        int runner = myShell();

        if(runner != 0){
            cout << "\nThanks for using myShell!" << endl;
            break;
        }
    }

    return 0;
}
