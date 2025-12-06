#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
  struct addrinfo hints;
  struct addrinfo* results;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(NULL, "3490", &hints, &results);
  if (status != 0) {
    std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
    return -1;
  }

  int socketToUse = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  if (socketToUse == -1) {
    return -1;  // temp
  }

  int bindStat = bind(socketToUse, results->ai_addr, results->ai_addrlen);
  if (bindStat == -1) {
    return -1;  // temp
  }

  freeaddrinfo(results);
  std::cout << '\n';
}
