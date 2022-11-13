#include <mutex>
#include <thread>
#include <string>
#include <iostream>

#include <WinSock2.h> 
#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
// include flag -lws2_32 if compiling with MinGW 
// otherwise you'll get a bunch of undefined reference compiler errors
// pragma didn't work with my MinGW

using namespace std;

// Chat Application that transmits messages using a UDP/IP socket
// Cesar Gutierrez

mutex Mutex;

void recvMsg(){
    Mutex.lock();
    const char* srcIP = "127.0.0.1";
    const short srcPort = 3515;
    const short msgLength = 1024;
    char inboundMessage[msgLength];
    sockaddr_in home;
    WSAData data;
    int size = sizeof(home);

    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET receivingDepartment = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    home.sin_family = AF_INET;
    inet_pton(AF_INET, srcIP, &home.sin_addr.s_addr);
    home.sin_port = htons(srcPort);
    bind(receivingDepartment, (sockaddr *)&home, sizeof(home));
    Mutex.unlock();

    while(true){
        // recvfrom(socket, char, int length, flags, socket address, socket address length)
        recvfrom(receivingDepartment, inboundMessage, msgLength, 0, (sockaddr *)&home, &size);
        Mutex.lock();
        cout << inboundMessage << endl;
        Mutex.unlock();
    }
}

void sendMsg(){
    Mutex.lock();
    const char* destIP = "127.0.0.1";
    const short destPort = 3514;
    const short msgLength = 1024;
    char packetMessage[msgLength] = "Gotta get that A+";
    sockaddr_in dest;
    WSAData data;

    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET shippingDepartment = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    dest.sin_family = AF_INET;
    inet_pton(AF_INET, destIP, &dest.sin_addr.s_addr);
    dest.sin_port = htons(destPort);
    bind(shippingDepartment, (sockaddr *)&dest, sizeof(dest));
    Mutex.unlock();

    while(true){
        cout << "What message would you like to send?" << endl;
        cin.getline(packetMessage, msgLength);
        sendto(shippingDepartment, packetMessage, strlen(packetMessage), 0, (sockaddr *)&dest, sizeof(dest));
    }

    closesocket(shippingDepartment);
    WSACleanup();
    exit(0);
}

int main(){
    thread A(sendMsg);
    thread B(recvMsg);
    A.join();
    B.join();
    return 0;
}
