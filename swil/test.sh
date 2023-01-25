#!/bin/bash
set -euo pipefail
RENODE_RUN_DIR=$(pwd)/renode-run
RENODE_VERSION='latest'
ARTIFACTS_PATH=''
renode_arguments=''
TESTS_TO_RUN='leon3_rtems.robot'

python3 -m venv swil-venv
. ./swil-venv/bin/activate

# Fix 'error: invalid command 'bdist_wheel''
pip3 install wheel

# Install renode-run script
pip install -q git+https://github.com/antmicro/renode-run

# Download renode
renode-run -a $RENODE_RUN_DIR download -d $RENODE_VERSION

# Run test suite
renode-run -a $RENODE_RUN_DIR test -- -r $ARTIFACTS_PATH "${renode_arguments[@]}" $TESTS_TO_RUN