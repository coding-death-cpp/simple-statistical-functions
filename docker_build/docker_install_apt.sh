#!/bin/bash

sudo apt install docker.io docker-compose

sudo usermod -aG docker $USER

echo Please reboot now.
