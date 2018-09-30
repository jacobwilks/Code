/*
 * Jacob Wilks
 * Eric Kyle Salas
 * CSCI 446
 * Spring 2017
 *
 * This template provides the framework you need for program 2. Complete the functions
 * defined and create any you feel are neccessary. stream-talk-client.c on Learn will
 * prove useful.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define SERVER_NAME "www.ecst.csuchico.edu"
#define SERVER_PORT "80"
#define REQUEST "GET /~ehamouda/file.html HTTP/1.0\n\n"


ssize_t readchunck( int sockfd, void *buf, size_t len )
{
	  int len_bytes;
//The MSG_WAITALL flag requests that the operation block until the full request is satisfied.
// This allows the socket to always get the same number of bytes and stay consistent.
    len_bytes=recv(sockfd,buf,len,MSG_WAITALL);
		if (len_bytes == -1)
    {
      perror("ReadChunck returned a -1 and errno was set");
      close(sockfd);
    }
	return len_bytes;
}

int main( int argc, char *argv[] )
{
//Variable list
	int chunck_len = atoi(argv[1]); // Saves the value frm argv[1] into chunck_len and saved as an int thanks to the atoi function
	char* tags = argv[2]; // Storing this and the chunck_len to be able to be used by the readchunck function
	int s;
	struct addrinfo hints;
	struct addrinfo *rp, *result;
  int total_chunck; // Used in do-while loop to determine how long the loop should run for
  char buffer[chunck_len];
  int total_tags = 0;//

//Check to make sure the user has the proper amount of arguments
	if (argc != 3){
		printf("Incorrect format of arguments. \n");
		return 1;
	}

	/* Translate host name into peer's IP address */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if ((s = getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &result)) != 0 ) {
    fprintf(stderr, "%s: getaddrinfo: %s\n", argv[0], gai_strerror(s));
    exit(1);
  }
	/* Iterate through the address list and try to connect */
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    if ((s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1 ) {
				continue;
      }
    if (connect(s, rp->ai_addr, rp->ai_addrlen) != -1) {
				break;
      }
    close(s);
  }//for loop close

  if (rp == NULL) {
    perror("stream-talk-client: connect");
    exit(1);
  }

	freeaddrinfo(result);
  //sends a message to your webserver and gets number of bytes sent back from webpage
  send(s,REQUEST,sizeof(REQUEST),0);

//We decided to use a do while loop over a while loop to ensure that the code was ran through
//atleast one time. We also were having issues of consistency in numbers when we were only using a while loop
do {
	total_chunck = readchunck(s,buffer,chunck_len);
	if(total_chunck == -1)
  {
    perror("readchunk returned an error while looping\n");
    exit(1);
  }
	else if(total_chunck == 0)
	{
		break;
	}
  else{
	char *temp_buff = buffer;
  //searching temp_buff for our tags, and when we find them increase the count
	while((temp_buff = strstr(temp_buff,tags))){
		total_tags++;
		temp_buff++;
	}//while
  }//else statement
  } while(total_chunck > 0); // Once it is  zero it will hit the else if and will then break out of the loop.

  //print statement to display count of tags used that user specifies
    printf("Number of %s instances was: %d\n",tags,total_tags);
}
