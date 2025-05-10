import numpy as np
import matplotlib.pyplot as plt

x_train = np.array([[2000, 5, 8, 8],
                   [1900, 5, 8, 8],
                   [1800, 4, 9, 9],
                   [1700, 4, 9, 9],
                   [1600, 5, 9, 9],
                   [1500, 4, 7, 9],
                   [1400, 3, 5, 6],
                   [1300, 3, 8, 9],
                   [1200, 3, 7, 4],
                   [1100, 5, 4, 7]])

y_train = np.array([1500,1450,1600,1400,1400,1200,400,800,600,650])
norm_x = np.zeros([x_train.shape[0],x_train.shape[1]])
norm_y = np.zeros([x_train.shape[0]])
norm_x = (x_train - np.mean(x_train,axis=0))/np.std(x_train,axis=0)

norm_y = (y_train-np.mean(y_train))/np.std(y_train)

w_in = np.array([3,2,7,6])
b_in = 1

# print((norm_y))
# plt.figure(1)
# plt.scatter(norm_x[:,0],norm_y)
# plt.figure(2)
# plt.scatter(norm_x[:,1],norm_y)
# plt.figure(3)
# plt.scatter(norm_x[:,2],norm_y)
# plt.figure(4)
# plt.scatter(norm_x[:,3],norm_y)
# plt.show()

def f_wb_x(i,w,x,b): #Give us F vec_w_b(vec_X)
    return (np.dot(w,x[i,:])+b)

def d_k(k,m,X,Y,W,B,a):
    der =0.
    for i in range(X.shape[0]):
        der+= (f_wb_x(i,W,X,B)-Y[i])*X[i,k]
    return a*der/m

def der_b(m,X,Y,W,B,a):
    der =0
    for i in range(X.shape[0]):
        der+= (f_wb_x(i,W,X,B)-Y[i])
    return a*der/m

def opt(X,Y,w_init,b_init,itr,a):
    w_fin = np.zeros([X.shape[1]])
    b_fin =0
    der = np.zeros([X.shape[1]])
    for i in range(itr):
        for j in range(X.shape[1]):
            der[j] = d_k(j,X.shape[0],X,Y,w_init,b_init,a)
        w_fin = w_init - der
        derb = der_b(X.shape[1],X,Y,w_init,b_init,a)
        b_fin = b_init - derb

        w_init = w_fin
        b_init = b_fin
    return w_init, b_init

def opt2(X,Y,w_init,b_init,itr,a):
    w_fin = np.zeros([X.shape[1]])
    b_fin =0
    der = np.zeros([X.shape[1]])
    for i in range(itr):
        for j in range(X.shape[1]):
            der[j] = d_k(j,X.shape[0],X,Y,w_init,b_init,a)
        w_fin = w_init - der
        derb = der_b(X.shape[1],X,Y,w_init,b_init,a)
        b_fin = b_init - derb

        w_init = w_fin
        b_init = b_fin

    
    return w_init, b_init

w,b = opt(norm_x,norm_y,w_in,b_in,100000,.001)

print(w,b)

while True:
    X_raw = np.array([
        int(input("size: ")),
        int(input("rooms: ")),
        int(input("view rating: ")),
        int(input("Comfort rating: "))
        ])
    x_mean = np.mean(x_train,axis=0)
    x_std = np.std(x_train,axis=0)

    X_norm = (X_raw-x_mean)/x_std
    price_pred_norm = np.dot(X_norm,w)+b
    price = price_pred_norm*np.std(y_train) + np.mean(y_train)

    print(f"{price:.2f}")
            
        