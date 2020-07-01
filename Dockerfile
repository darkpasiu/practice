FROM ubuntu:20.10

USER root

RUN apt-get update && DEBIAN_FRONTEND="noninteractive" apt-get -y install g++ cmake lcov valgrind git

COPY . /opt/dockerExample

WORKDIR /opt/dockerExample

RUN mkdir -p build

WORKDIR /opt/dockerExample/build

RUN cmake ..
RUN make tests