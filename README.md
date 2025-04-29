## 👥 Authors

- [@stefancourt](https://github.com/stefancourt)

## 🌐 Overview
This software contains anomaly generation where anomalies are created within a dataset that is specifically used for classification. This dataset can then use the anomaly detection algorithms created to drop the anomalies from the dataset, classifying the dataset with anomalies and with anomalies dropped give different accuracy scores. the dataset is then passed to a random forest regressor algorithm to generate values for cells. This is then classified and a accuracy score is given. Along with this multiple graphs are present throughout the notebooks that contain many different measurable metrics.

## 📋 Table of Contents

- [🌐 Overview](#overview)
- [📦 Requirements](#requirements)
- [🌱 Configuring the Virtual Environment](#running-the-virtual-environment)
- [🚀 Launching the Application](#running-the-program)
- [🌲 Project Structure](#project-structure) 

## 📦 Requirements
The following libraries and packages are required to run this application. Ensure that you have the correct versions installed in your development environment.
- [python](https://www.python.org) 3.11.9
- [cmake](https://cmake.org/download/) 3.31.5
- [numpy](https://numpy.org) 2.2.1
- [pandas](https://pandas.pydata.org/docs/) 2.2.3
- [scikit-learn](https://scikit-learn.org/stable/) 1.6.1
- [matplotlib](https://matplotlib.org) 3.10.0
- [cvxopt](https://cvxopt.org) 1.3.2
- [nbformat](https://nbformat.readthedocs.io/en/latest/) 5.10.4
- [seaborn](https://seaborn.pydata.org) 0.13.2
- [pybind11](https://pybind11.readthedocs.io/en/stable/installing.html) 2.13.6


## 🌱 Configuring the Virtual Environment
1. Make sure that [Python 3.11.9](https://www.python.org/downloads/macos/) is installed on the system
2. Ensure [cmake](https://cmake.org/download/) is installed on the system
3. Navigate to the **Research Project Code/**.=
4. Run the following commands to activate the virtual environment and install all dependencies:

### On Mac
```bash
chmod +x mac-commands.sh
./mac-commands.sh
```

### On Windows
```bash
win-commands.bat
```
## 🚀 Running the Application
The below step is not needed when using a UNIX based operating system as the final code submission for ECMM428 Individual Research Project contains the build directory along with the cmake file already created within it which has been created using a UNIX based system, however if using a Windows system to run the program the instructions below must be followed.

To make sure the cmake files are installed correctly it is needed to input your absolute path into the placeholders where it states "Enter Your Absolute Path Here", within either the *ocsvm_exec.bat* file if on Windows of the *ocsvm_exec.sh* file if on UNIX. This needs to point to the locations where your cmake file is for *cmake*, pybind file is for *-DCMAKE_PREFIX_PATH* and python executable file are for *-DPython_EXECUTABLE*. The following can then be run from within the **Research Project Code/** folder to install the cmake file correctly.

### On Mac
```bash
chmod +x C_files/ocsvm_exec.sh

./C_files/ocsvm_exec.sh
```

### On Windows
```bash
call C_files/ocsvm_exec.bat
```

If all steps have been adhered to then all notebooks should be runnable with the **main.ipynb** notebook containing all main functions utilised within the applications along with graphs and scores.

## 🌲 Project Structure
Any (item) means multiple files of type *item*

```plaintext
Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies/
├── Research Project Code/
│   ├── Algorithms.ipynb
│   ├── Anomaly Generation.ipynb
│   ├── C_OCSVM.ipynb
│   ├── Cell Generation.ipynb
│   ├── Classification.ipynb
│   ├── DBSCAN.ipynb
│   ├── Isolation Forest.ipynb
│   ├── One-Class SVM.ipynb
│   ├── main.ipynb
│   ├── requirements.txt
│   ├── win-commands.bat
│   ├── mac-commands.sh
│   ├── C_files/
│   │   └── (C files)
│   ├── Datasets/
│   │   └── (CSV Datasets)
│   ├── build/
│   │   └── (Executable files)
│   └── venv/
├── LICENSE
└── README.md
```