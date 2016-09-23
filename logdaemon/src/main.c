#include <config.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <systemd/sd-journal.h>

int main (void) {
	sd_journal_print(LOG_INFO, "Starting: " PACKAGE_STRING);
	while (true) {
		sd_journal_print(LOG_INFO, "Hello World, this is PID %lu!", (unsigned long) getpid());
		sleep(5);
	}
	return 0;
}
