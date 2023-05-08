FROM ubuntu:latest

WORKDIR /battleship

COPY . .

RUN echo 'alias battleship="/battleship/PA8main"' >> ~/.bashrc

RUN apt-get update

RUN apt install make

RUN apt install -y g++

RUN make PA8main