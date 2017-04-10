import csv
import math
import matplotlib.pyplot as plt

def mse(label, x):
    return sum([math.pow(4 - float(i), 2) for i in x])/2

def cee(label, x):
    return -sum([float(i) * math.log(label)for i in x])


data = []
with open('error_data.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        data.extend(row)

print(mse(4, data))
print(cee(4, data))

x = range(0, len(data))
y = [4 for i in range(0, len(data))]

plt.plot(y, color='r')
plt.scatter(x, data)
plt.show()
