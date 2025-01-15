#!/bin/bash

# Create virtual environment
python -m venv venv

# Activate virtual environment
source venv/bin/activate

# Install ipykernel
pip install ipykernel

# Allow use of virtual environment within notebook
python -m ipykernel install --name=venv

# Install dependencies within the virtual environment
pip install -r requirements.txt