import numpy as np
import matplotlib.pyplot as plt

def load_data():
    data = np.loadtxt("data/ex1data1.txt", delimiter=',')
    X = data[:,0]
    y = data[:,1]
    return X, y

x,y = load_data()

plt.scatter(x,y)
plt.show()




# x_train = np.reshape(np.array([x,x**2,x**3,x**4,x**5]),(np.shape(x)[0],5))

x_train = np.column_stack([x**i for i in range(1, 10)])

x_norm = (x_train - np.mean(x_train,axis=0)) / np.std(x_train,axis=0)
y_norm = (y-np.mean(y))/np.std(y)

def f_wb_x(i,x,w,b):
    fx = np.dot(w,x[i,:])+b
    return fx

m =np.shape(x)

def cost_J(x,y,w,b):
    # cost=0
    # for i in range(np.shape(x)[0]):
    #     cost+= (f_wb_x(i,x,w,b)-y[i])**2
        
    # return cost/(2*np.shape(x)[0])
    
    return np.sum((np.dot(x,w) + b - y)**2)/(2*np.shape(x)[0])

def dj_dw(k,x,y,w,b):
    der=0
    for i in range(np.shape(x)[0]):
        der += (f_wb_x(i,x,w,b)-y[i])*x[i,k]
    return der/(np.shape(x)[0])

def dj_db(x,y,w,b):
    der=0
    for i in range(np.shape(x)[0]):
        der += (f_wb_x(i,x,w,b)-y[i])
    return der/(np.shape(x)[0])





def grad_des(x,y,itr,a):
    w_init = np.ones(np.shape(x_train)[1])
    b_init = 0
    cost_hist = np.zeros([itr])
    for i in range(itr):
        w_tmp = np.zeros(np.shape(x_train)[1])
        b_tmp = 0
        for j in range(np.shape(x)[1]):
            w_tmp[j]=w_init[j]-(a*dj_dw(j,x,y,w_init,b_init))
        b_tmp = b_init-(a*dj_db(x,y,w_init,b_init))
        
        
        w_init = np.copy(w_tmp)   
        b_init = b_tmp
        cost_hist[i]=cost_J(x,y,w_init,b_init)
    return w_init,b_init,cost_hist

w,b,cost_h = grad_des(x_norm,y_norm,10000,.01)
print(w,b)

x_mean = np.mean(x_train,axis=0)
x_std = np.std(x_train,axis=0)

x_new = np.arange(100)
# x_in = np.reshape(np.array([x_new,x_new**2,x_new**3,x_new**4,x_new**5]),(1000,5))
x_in = np.column_stack([x_new**i for i in range(1, 10)])
x_n = (x_in-x_mean)/x_std

y_n = np.dot(x_n,w)+b
y_std = np.std(y)
y_mean = np.mean(y)
y_out = y_n*y_std +y_mean

# plt.scatter(x,y,c="cyan")
# plt.show()

# plt.scatter(x,y)
# plt.plot(x_new,y_out)

# plt.show()
plt.figure(figsize=(10,4))
plt.subplot(1,2,1)
plt.scatter(x, y, color="cyan", label="Data")
plt.plot(x_new, y_out, color="red", label="Polynomial Fit")
plt.legend()
plt.xlabel("x")
plt.ylabel("y")
plt.title("Polynomial Regression Fit")
plt.subplot(1,2,2)
plt.plot(np.arange(10000),cost_h)
plt.show()



