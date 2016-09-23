#include <config.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <systemd/sd-journal.h>
#include <systemd/sd-daemon.h>

int main (void) {
 	pid_t  pid;
	uint64_t watchdog_interval;
  	int watchdog_required;

	sd_journal_print(LOG_INFO, "This is " PACKAGE_STRING " on PID %lu.", (unsigned long) getpid());

	pid = fork();
     	if (pid == 0) {
		sd_journal_print(LOG_INFO, "This is the child on PID %lu.", (unsigned long) getpid());
		while (true) {
			sd_journal_print(LOG_INFO, "Running the real service...");
			sleep(60);
		}
	} else {
		sd_journal_print(LOG_INFO, "This is the parent on PID %lu.", (unsigned long) getpid());

	  	// Obtain the necessary interval.
	  	watchdog_required = sd_watchdog_enabled(1, &watchdog_interval);

	  	// For the purpose of this tutorial, exit if no watchdog is set.
	  	if (!watchdog_required) {
			exit(1);
		}

	   	sd_notify(0, "READY=1");
	  	while (true) {
			sd_notify(0, "WATCHDOG=1");

			// Sleep for half the defined interval.
		  	usleep(watchdog_interval / 2);
		}
	}

	return 0;
}
