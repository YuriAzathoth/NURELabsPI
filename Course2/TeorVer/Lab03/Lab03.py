import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import pandas as pd
from numpy import random, sqrt, log, sin, cos, pi, log

def norm(arr):
    return (arr-min(arr))/(max(arr)-min(arr))

def exponent(a1):
    return -log(a1)

def gauss(a1,a2):
  z1 = sqrt(-2*log(a1))*cos(2*pi*a2)
  z2 = sqrt(-2*log(a1))*sin(2*pi*a2)
  return z1,z2

def show_equal(a1):
	x1 = pd.DataFrame(a1, columns=['values'])
	fig, ax = plt.subplots()
	x1.plot.kde(ax=ax, legend=False, title='Равномерное распределение')
	x1.plot.hist(density=True, ax=ax)
	ax.grid(axis='y')
	plt.show()

def show_exp(a1):
	x2 = pd.DataFrame(norm(exponent(a1)), columns=['values'])
	fig, ax = plt.subplots()
	x2.plot.kde(ax=ax, legend=False, title='Экспоненциальное распределение')
	x2.plot.hist(density=True, ax=ax)
	ax.grid(axis='y')
	plt.show()

def show_norm(a1,a2):
	x3 = pd.DataFrame(norm(gauss(a1, a2)[0]), columns=['values'])
	fig, ax = plt.subplots()
	x3.plot.kde(ax=ax, legend=False, title='Нормальное распределение')
	x3.plot.hist(density=True, ax=ax)
	ax.grid(axis='y')
	plt.show()

a1 = random.random(2000)
a2 = random.random(2000)

show_equal(a1)
show_exp(a1)
show_norm(a1,a2)