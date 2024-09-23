FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m ret2plt
RUN chown -R root:root /home/ret2plt
RUN chmod -R 755 /home/ret2plt
CMD ["/usr/sbin/xinetd", "-dontfork"]
