@echo off

REM Create virtual environment
python3 -m venv venv

REM Activate virtual environment
call venv\Scripts\activate

REM Install ipykernel
pip3 install ipykernel

REM Allow use of virtual environment within notebook
python3 -m ipykernel install --user --name=venv

REM Install dependencies within the virtual environment
pip3 install -r requirements.txt

REM Install C dependencies to allow python file to run
call C_files/ocsvm_exec.bat