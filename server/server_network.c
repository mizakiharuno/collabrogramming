/* server_network.c

   This program handles socket creation and network communication.

   Author:        Brian Garrison
   Date-Started:  10/10/2016
   Date-Finished:
   Modifications:
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

// Sets up the constants for our connection (ip address and port)
const char *ipaddr = "192.0.0.1";
const char *port = "4794";

// Creates and sets up the address info structure
int status;
struct addrinfo my_addr;
struct addrinfo *servinfo; // will point to the results

int main() {
  memset(&my_addr, 0, sizeof my_addr);
  my_addr.ai_family = AF_UNSPEC;
  my_addr.ai_socktype = SOCK_STREAM;
  my_addr.ai_flags = AI_PASSIVE;

  printf("%d\n", getaddrinfo("127.0.2.64", port, &my_addr, &servinfo));

}
