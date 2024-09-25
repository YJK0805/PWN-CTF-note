FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m ret2plt_adv
RUN chown -R root:root /home/ret2plt_adv
RUN chmod -R 755 /home/ret2plt_adv
CMD ["/usr/sbin/xinetd", "-dontfork"]
