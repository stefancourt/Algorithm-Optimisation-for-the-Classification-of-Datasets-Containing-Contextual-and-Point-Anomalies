@echo off

REM Create virtual environment
python -m venv venv

REM Activate virtual environment
call venv\Scripts\activate

REM Install ipykernel
pip install ipykernel

REM Allow use of virtual environment within notebook
python -m ipykernel install --name=venv

REM Install dependencies within the virtual environment
pip install -r requirements.txt

REM Install C dependencies to allow python file to run
call C_files/ocsvm_exec.bat