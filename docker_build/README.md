# C++20 build pipeline

Simple pipeline consisting of meson build system running on docker (ubuntu 20.04 + g++10).

Just works (TM).

## init

First you need to install packages:
* docker  # for running containers
* docker-compose  # simplifies container management

Then you need to add yourself to `docker` group.

For all above you need to run `docker_1_install_apt.sh` script.

Reboot after that, and then it should work... 

## build and run

There is `docker_2_build_and_run.sh` script. Run it every time you modify something.

First run will take few minutes, but it will be faster on next iterations as it caches a lot (as well as meson/ninja).

There is also a script for cache removal, if you think cache gets too big.