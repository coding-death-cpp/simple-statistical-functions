# C++20 build pipeline

Simple pipeline consisting of meson build system running on docker (ubuntu 20.04 + g++10).

Just works (TM).

## init

First you need to install packages:
* docker  # for running containers
* docker-compose  # simplifies container management

Then you need to add yourself to `docker` group.

For all above you need to run `docker_install_apt.sh` script.

Reboot after that, and then it should work... 

## build and run

There is `docker_build_and_run.sh` script. Run it every time you modify something.

First run will take few minutes, but it will be faster on next iterations as it caches a lot (as well as meson/ninja).

There is also a script for cache removal, if you think cache gets too big.

# interactive mode

You can access container's shell by running `docker_shell.sh` script. 
It builds a container, runs it and executes bash inside. 
Default dir is `/workdir`, but you'll have more insight after `cd /'.