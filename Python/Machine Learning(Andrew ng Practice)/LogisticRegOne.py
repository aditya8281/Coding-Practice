import numpy as np
import matplotlib.pyplot as plt

X_train = np.arange(100)
X_train = np.reshape(X_train,[100,1])
y_train = np.ones(100)
for i in range(100):
    if i < 40:
        y_train[i] = 0
X_mean = np.mean(X_train,axis=0)
X_std = np.std(X_train,axis=0)
X_norm = (X_train-X_mean)/ X_std


def z_x(X,w,b):
    z = np.dot(X,w)+b
    return z

def sigmoid(X,w,b):
    z = z_x(X,w,b)
    sig_z = 1/(1+np.exp(-z))
    return sig_z

def cost(X,y,w,b):
    m = np.shape(X)[0]
    sig = sigmoid(X,w,b)
    
    c = -(1/m)*np.sum(y*np.log(sig+1e-15)+(1-y)*np.log(1-sig+1e-15))
    
    return c
def reg(X,y,w,b,itr,a):
    m = np.shape(X)[0]
    for i in range(itr):
        error = sigmoid(X,w,b)-y
        w-= (a/m)*np.dot(X.T,error)
        b-= (a/m)*np.sum(error)
        
        if((i+1)%1000==0):
            print(f"at itr {i} cost = {cost(X,y,w,b)}")
        
    return w,b

w_init = np.zeros(1)
b_init = 0

w_init,b_init = reg(X_norm,y_train,w_init,b_init,1000000,0.99)


x_vals = np.linspace(X_train.min(), X_train.max(), 500).reshape(-1, 1)
x_vals_norm = (x_vals - X_mean) / X_std
y_probs = sigmoid(x_vals_norm, w_init, b_init)

plt.scatter(X_train, y_train, label="Training data", c=y_train, cmap='bwr', edgecolors='k')
plt.plot(x_vals, y_probs, color='green', label='Sigmoid prediction')
plt.xlabel("Exam 1 Score")
plt.ylabel("Admission Probability")
plt.title("Logistic Regression Fit")
plt.legend()
plt.grid(True)
plt.show()