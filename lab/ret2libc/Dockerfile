FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m ret2libc
RUN chown -R root:root /home/ret2libc
RUN chmod -R 755 /home/ret2libc
CMD ["/usr/sbin/xinetd", "-dontfork"]
