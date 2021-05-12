import matplotlib.pyplot as plt

file = open('Time_data.txt', 'r')
#read informaion from file
line_list = file.readlines()
amount_elem = []
time_data = []
N = 10;
for elem in line_list:
    time_data.append(int(elem))
    amount_elem.append(N)
    N *= 5
file.close()
#draw the graph
plt.figure(figsize = (15,10))
plt.grid(True)
plt.errorbar(amount_elem, time_data, fmt = 'o', markersize = None, color ='red', label = u' ')
plt.title(r'$Зависимость\:\:time(amount)\:\:для\:\: quick&sort$', size = 20)
plt.xlabel(r'$amount\:\:$', fontsize = 20)
plt.ylabel(r'$time,\:\: ms$', fontsize = 20)
plt.show()

