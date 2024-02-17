/**
 *
 *
 *
 */
#include "server.h"

int main() {

  atexit(cleanup); // Clear the socket on exit

  // Initialize Winsock
  if (WSAStartup(winsock_version, &wsaData) != 0) {
    printf("WSAStartup failed.\n");
    return 1;
  }

  // Create a socket for listening
  if ((listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) ==
      INVALID_SOCKET) {
    printf("Error creating socket: %d\n", WSAGetLastError());
    WSACleanup();
    return 1;
  }

  // Bind the socket
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  serverAddr.sin_port = htons(PORT); // Choose any port you want
  if (bind(listenSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) ==
      SOCKET_ERROR) {
    printf("Bind failed with error: %d\n", WSAGetLastError());
    closesocket(listenSocket);
    WSACleanup();
    return 1;
  }

  // Listen for incoming connections
  if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
    printf("Listen failed with error: %d\n", WSAGetLastError());
    closesocket(listenSocket);
    WSACleanup();
    return 1;
  }

  printf("Server listening on port %d...\n", PORT);

  // Accept a client connection
  if ((clientSocket = accept(listenSocket, (struct sockaddr *)&clientAddr,
                             &clientAddrLen)) == INVALID_SOCKET) {
    printf("Accept failed: %d\n", WSAGetLastError());
    closesocket(listenSocket);
    WSACleanup();
    return 1;
  }

  printf("Client connected.\n");

  // Receive data from client
  while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
    // Echo received data back to client
    send(clientSocket, buffer, bytesReceived, 0);
  }

  if (bytesReceived < 0) {
    printf("Receive failed: %d\n", WSAGetLastError());
  }

  // Close sockets and cleanup
  closesocket(clientSocket);
  closesocket(listenSocket);

  return 0;
}

void cleanup() { WSACleanup(); }