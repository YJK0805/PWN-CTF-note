FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m stack_pivoting
RUN chown -R root:root /home/stack_pivoting
RUN chmod -R 755 /home/stack_pivoting
CMD ["/usr/sbin/xinetd", "-dontfork"]
