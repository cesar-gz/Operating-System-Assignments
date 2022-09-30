#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

// ConsoleApplication1.cpp : Simple Command Line Interpreter.
// Copyright (c) Cesar Gutierrez 9/29/2022
//

void print26times(char A, int X){
    // open file
    ofstream file("synch.txt");

    if(A == 'A'){

        // print this line 20 times
        for(int i = 0; i < 20; i++){
            // print this array
            for(int j = 0; j < 26; j++){
                file << A << " ";
                A = (char)(A+1);
            }
            // print new line and reset the value
            file << "\n";
            A = 'A';
        }

        // close file
        file.close();
        return;
    }
    else if(X == 1){
        // print this line 20 times
        for(int i = 0; i < 20; i++){
            // print this array
            for(int j = 0; j < 26; j++){
                file << X  << " ";
                X++;
            }
            // print new line, and reset the value
            file << "\n";
            X = 1;
        }

        // close file
        file.close();
        return;
    }
}

DWORD WINAPI ThreadA(){
    print26times('A', 0);
    return 0;
}

int main(){

    // create and close a file called synch.txt
    ofstream file("synch.txt");
    file.close();

    // Create thread A
    HANDLE handleThread;
                DWORD thread;
                handleThread = CreateThread(
                    NULL,                            // default security attribute
                    0,                               // default 1MB size
                    (LPTHREAD_START_ROUTINE)ThreadA, // function address to be called
                    0,                               // function parameter to pass, takes pointer
                    0,                               // creation flag
                    &thread                          // address of thread
                );
                WaitForSingleObject(handleThread, INFINITE);
                CloseHandle(handleThread);

    return 0;
}
