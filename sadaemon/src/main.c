#include <config.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <systemd/sd-journal.h>
#include <systemd/sd-daemon.h>

int main(void) {
	int listen_fd, communication_fd;
   	char communication_buffer[128];

  	sd_journal_print(LOG_INFO, "Starting: " PACKAGE_STRING);

	if (sd_listen_fds(0) != 1) {
        	fprintf(stderr, "Zero or too many file descriptors received.\n");
	        return 1;
	}

	listen_fd = SD_LISTEN_FDS_START + 0;

	// Loop to handle successive clients.
  	while (true) {
    		communication_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
		sd_journal_print(LOG_INFO, "Client connected.");

		// Loop to handle echoing to the connected client.
		while(true) {
			bzero(communication_buffer, 100);
			read(communication_fd, communication_buffer, 100);
			sd_journal_print(LOG_INFO, "Received: %s", communication_buffer);
			write(communication_fd, communication_buffer, strlen(communication_buffer) + 1);
		}
	}

  	return 0;
}
