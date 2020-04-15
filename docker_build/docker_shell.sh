#!/bin/bash

docker-compose build docker_builder
docker-compose run docker_builder bash

