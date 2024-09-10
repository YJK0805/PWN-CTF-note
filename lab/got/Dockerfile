FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m got
RUN chown -R root:root /home/got
RUN chmod -R 755 /home/got
CMD ["/usr/sbin/xinetd", "-dontfork"]
