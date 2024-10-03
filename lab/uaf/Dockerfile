FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m uaf
RUN chown -R root:root /home/uaf
RUN chmod -R 755 /home/uaf
CMD ["/usr/sbin/xinetd", "-dontfork"]
