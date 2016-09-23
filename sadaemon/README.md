# Socket-Activated Daemon Tutorial

## Installing Dependencies

    sudo dnf install systemd-devel telnet telnet-server

## Building and Installing

    autoreconf --install
    ./configure
    make
    sudo make install
    sudo chcon --type=telnetd_exec_t /usr/local/bin/sadaemon

## Running

    sudo systemctl start sadaemon.socket
    telnet localhost 23
