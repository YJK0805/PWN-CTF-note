FROM ubuntu:22.04
MAINTAINER YJK

RUN apt-get update
RUN yes | unminimize
RUN apt-get install -y tini iproute2 iputils-ping net-tools netcat
RUN apt-get install -y openssh-server sudo vim grep gawk rsync tmux diffutils file
RUN apt-get install -y gcc gdb make yasm nasm tcpdump python3 python3-pip python3-virtualenv
RUN apt-get install -y gcc-multilib g++-multilib
RUN apt-get install -y libc6-dbg dpkg-dev
RUN apt-get install -y curl git zsh
RUN apt-get install -y ruby-dev wget
RUN pip3 install pwntools capstone filebytes keystone-engine ropper
RUN gem install seccomp-tools
RUN gem install one_gadget
RUN mkdir /var/run/sshd

RUN echo 'PermitEmptyPasswords yes' >> /etc/ssh/sshd_config
RUN sed -i 's/nullok_secure/nullok/' /etc/pam.d/common-auth

RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER root
RUN git clone https://github.com/pwndbg/pwndbg ~/pwndbg
RUN cd ~/pwndbg && ./setup.sh
RUN git clone https://github.com/scwuaptx/Pwngdb.git ~/Pwngdb
RUN cp ~/Pwngdb/.gdbinit ~/
RUN rm -rf ~/.gdbinit
RUN echo "source ~/pwndbg/gdbinit.py" >> ~/.gdbinit
RUN echo "source ~/Pwngdb/pwngdb.py" >> ~/.gdbinit
RUN echo "source ~/Pwngdb/angelheap/gdbinit.py" >> ~/.gdbinit
RUN echo "define hook-run" >> ~/.gdbinit
RUN echo "python" >> ~/.gdbinit
RUN echo "import angelheap" >> ~/.gdbinit
RUN echo "angelheap.init_angelheap()" >> ~/.gdbinit
RUN echo "end" >> ~/.gdbinit
RUN echo "end" >> ~/.gdbinit

USER root
# run the service
EXPOSE 22
ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["/usr/sbin/sshd", "-D"]
