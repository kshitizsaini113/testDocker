FROM centos
RUN yum update -y
RUN dnf install gcc-c++ -y
RUN mkdir /mutex
RUN mkdir /test
COPY ./src /mutex