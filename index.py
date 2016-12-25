# import all the necesary libraries

from sklearn import datasets, svm
from matplotlib import pyplot as plot
from numpy import genfromtxt

# init boston dataset and retrieve required data
boston = datasets.load_boston(False)
boston_data = boston.data

# init my sample datasets
acc_data = genfromtxt("sample.csv",delimiter=",")

plot.plot(acc_data)
plot.ylabel('rand')
plot.show()

#eof
