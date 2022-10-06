#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

// ConsoleApplication1.cpp : Simple Command Line Interpreter.
// Copyright (c) Cesar Gutierrez 10/05/2022
//

HANDLE myMutex;
HANDLE handleThreadA;
HANDLE handleThreadB;
DWORD threadA;
DWORD threadB;

void print26times(char A, int X){

    ofstream file("synch.txt");

    WaitForSingleObject(myMutex, INFINITE);

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
    }

    ReleaseMutex(myMutex);

    file.close();
}

DWORD WINAPI ThreadA(){
    char letter = 'Z';
    int number = 1;
    print26times(letter, number);
    return 0;
}

DWORD WINAPI ThreadB(){
    char letter2 = 'A';
    int number2 = 0;
    print26times(letter2, number2);
    return 0;
}

int main(){

    ofstream file("synch.txt");
    file.close();

    myMutex = CreateMutex(
        NULL,   // no security attributes
        FALSE,  // mutex owner is no one right now
        NULL    //no name
    );

    handleThreadA = CreateThread(
        NULL,                            // default security attribute
        0,                               // default 1MB size
        (LPTHREAD_START_ROUTINE)ThreadA, // function address to be called
        0,                               // function parameter to pass, takes pointer
        0,                               // creation flag
        &threadA                         // address of thread
    );

    handleThreadB = CreateThread(
        NULL,                            // default security attribute
        0,                               // default 1MB size
        (LPTHREAD_START_ROUTINE)ThreadB, // function address to be called
        0,                               // function parameter to pass, takes pointer
        0,                               // creation flag
        &threadB                         // address of thread
    );

    WaitForSingleObject(handleThreadA, INFINITE);
    WaitForSingleObject(handleThreadB, INFINITE);

    CloseHandle(handleThreadA);
    CloseHandle(handleThreadB);

    return 0;
}