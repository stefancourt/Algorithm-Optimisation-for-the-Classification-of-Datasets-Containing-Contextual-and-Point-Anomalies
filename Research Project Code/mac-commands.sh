#!/bin/bash

# Create virtual environment
python3 -m venv venv

# Activate virtual environment
source venv/bin/activate

# Install ipykernel
pip3 install ipykernel

# Allow use of virtual environment within notebook
python3 -m ipykernel install --user --name=venv

# Install dependencies within the virtual environment
pip3 install -r requirements.txt

# Install C dependencies to allow python file to run
# chmod +x C_files/ocsvm_exec.sh

# ./C_files/ocsvm_exec.sh