# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.234.0/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version (use ubuntu-22.04 or ubuntu-18.04 on local arm64/Apple Silicon): ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="jammy"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

RUN apt-get update && \
    apt-get install -qq -y git libssl-dev libcurl4-openssl-dev uncrustify cmake g++

RUN git clone https://libwebsockets.org/repo/libwebsockets --depth 1 --branch v4.2-stable && \
    cd libwebsockets && \
    mkdir build && \
    cd build && \
    cmake -DLWS_WITHOUT_TESTAPPS=ON -DLWS_WITHOUT_TEST_SERVER=ON-DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON \
      -DLWS_WITHOUT_TEST_PING=ON -DLWS_WITHOUT_TEST_CLIENT=ON -DCMAKE_C_FLAGS="-fpic" -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make && make install

# Build pre-requisite: libyaml
RUN git clone https://github.com/yaml/libyaml --depth 1 --branch release/0.2.5 && \
    cd libyaml && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_TESTING=OFF  -DBUILD_SHARED_LIBS=ON .. && \
    make && \
    make install

