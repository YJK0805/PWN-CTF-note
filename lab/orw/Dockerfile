FROM ubuntu:22.04
LABEL org.opencontainers.image.authors="YJK"
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m orw
RUN chown -R root:root /home/orw
RUN chmod -R 755 /home/orw
CMD ["/usr/sbin/xinetd", "-dontfork"]
