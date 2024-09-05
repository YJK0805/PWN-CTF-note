FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m bof
RUN chown -R root:root /home/bof
RUN chmod -R 755 /home/bof
CMD ["/usr/sbin/xinetd", "-dontfork"]
