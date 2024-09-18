FROM ubuntu:22.04
LABEL org.opencontainers.image.authors="YJK"
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m rop
RUN chown -R root:root /home/rop
RUN chmod -R 755 /home/rop
CMD ["/usr/sbin/xinetd", "-dontfork"]
