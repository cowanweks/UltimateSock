#pragma once

#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>

//
static int PORT = 3000;
static WSADATA wsaData;
static WORD winsock_version = MAKEWORD(2, 2);
static SOCKET listenSocket, clientSocket;
static struct sockaddr_in serverAddr, clientAddr;
static int clientAddrLen = sizeof(clientAddr);
static char buffer[1024];
static int bytesReceived;

// Cleanup the socket
static void cleanup();
