FROM centos
RUN mkdir /mutex
RUN mkdir /test
COPY . /mutex