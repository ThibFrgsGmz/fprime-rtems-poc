ARG VARIANT="22.04"
FROM ubuntu:${VARIANT} as base

ARG DEBIAN_FRONTEND=noninteractive

# Install required packages as well as setup the prettier bash prompt and a
# Python virtual environment.
RUN apt-get update && apt-get install -y --no-install-recommends \
    openssh-server \
    curl \
    wget \
    gnupg \
    git \
    build-essential \
    cmake \
    gdb-multiarch \
    default-jre \
    python3 \
    python3-setuptools \
    python3-pip \
    python3-venv \
    && rm -rf /var/lib/apt/lists/* \
    && python3 -m venv /tmp/fprime-venv \
    && . /tmp/fprime-venv/bin/activate \
    && python3 -m pip install -U --upgrade pip setuptools setuptools_scm wheel \
    && printf '\n[ -d "%s" ] && . %s/bin/activate\n' /tmp/fprime-venv /tmp/fprime-venv >> ~/.bashrc \
    && echo 'eval "$(register-python-argcomplete fprime-cli)"' >> ~/.bashrc

# Install Renode
ARG RENODE_PKG= https://github.com/renode/renode/releases/download/v1.13.3/renode-1.13.3.linux-portable.tar.gz
RUN wget $RENODE_PKG \
      tar -xvzf renode-1.13.3.linux-portable.tar.gz
    
ENV RENODE_INSTALL_DIR=/workspaces/renode
ENV PATH=${RENODE_INSTALL_DIR}:${PATH}