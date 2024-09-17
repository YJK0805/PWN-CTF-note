FROM ubuntu:22.04
LABEL org.opencontainers.image.authors="YJK"
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m ret2sc
RUN chown -R root:root /home/ret2sc
RUN chmod -R 755 /home/ret2sc
CMD ["/usr/sbin/xinetd", "-dontfork"]
