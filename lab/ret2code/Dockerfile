FROM ubuntu:22.04
LABEL org.opencontainers.image.authors="YJK"
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m ret2code
RUN chown -R root:root /home/ret2code
RUN chmod -R 755 /home/ret2code
CMD ["/usr/sbin/xinetd", "-dontfork"]
