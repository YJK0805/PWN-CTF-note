FROM ubuntu:22.04
MAINTAINER YJK
RUN apt-get update && apt-get install -y xinetd
RUN useradd -m online_shopping
RUN chown -R root:root /home/online_shopping
RUN chmod -R 755 /home/online_shopping
CMD ["/usr/sbin/xinetd", "-dontfork"]
