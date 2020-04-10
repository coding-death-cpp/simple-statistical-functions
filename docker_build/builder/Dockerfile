FROM ubuntu:20.04

RUN apt update
RUN apt install -y software-properties-common apt-utils
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt update
RUN apt install -y build-essential meson ninja-build tree gcc-10 g++-10
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 60 --slave /usr/bin/g++ g++ /usr/bin/g++-10
RUN gcc -v

WORKDIR /workdir

COPY build.sh /workdir/build.sh
COPY run.sh /workdir/run.sh
COPY build_and_run.sh /workdir/build_and_run.sh

CMD ["/workdir/build_and_run.sh"] 
