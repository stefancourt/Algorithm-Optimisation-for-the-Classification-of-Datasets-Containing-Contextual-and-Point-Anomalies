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
- [numpy](https://numpy.org) 2.2.1
- [pandas](https://pandas.pydata.org/docs/) 2.2.3
- [scikit-learn](https://scikit-learn.org/stable/) 1.6.1
- [matplotlib](https://matplotlib.org) 3.10.0
- [cvxopt](https://cvxopt.org) 1.3.2
- [nbformat](https://nbformat.readthedocs.io/en/latest/) 5.10.4
- [seaborn](https://seaborn.pydata.org) 0.13.2


## 🌱 Configuring the Virtual Environment
### On Mac
1. Make sure that [Python 3.11.x](https://www.python.org/downloads/macos/) is installed on the device
2. Navigate to the **Research Project Code/**.
3. Run the following commands to activate the virtual environment:

```bash
chmod +x commands.sh
./commands.sh
```

### On Windows

## 🚀 Running the Application

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