import numpy as np
import matplotlib.pyplot as plt

def load_data(filename):
    data = np.loadtxt(filename, delimiter=',')
    X = data[:,:2]
    y = data[:,2]
    return X, y

X_train, y_train = load_data("data/ex2data1.txt")

X_final = np.column_stack([X_train[:,0],X_train[:,1],X_train[:,0]**2,X_train[:,1]**2,X_train[:,0]*X_train[:,1],X_train[:,0]**3,X_train[:,1]**3])
w_train = np.ones([np.shape(X_final)[1]])
b_train = 0

X_norm = (X_final-np.mean(X_final,axis=0))/np.std(X_final,axis=0)


def z_x(X,w,b):
    m=np.shape(X)[0]
    z=np.zeros(m)
    for i in range(m):
        z[i] = np.dot(X[i,:],w)+b
    return z

def sigmoid(X,w,b):
    z = z_x(X,w,b)
    sig_z = 1/(1+np.exp(-z))
    return sig_z

def cost(X,y,w,b):
    m = np.shape(X_final)[0]
    c= -(1/m)*np.sum((y*np.log(sigmoid(X,w,b))+(1-y)*np.log(1-sigmoid(X,w,b))))
    return c


def reg(X,y,w_init,b_init,itr,a):
    m = np.shape(X)[0]
    w = np.copy(w_init)
    b = b_init
    for i in range(itr):
        error = sigmoid(X,w,b)-y
        w -= (a/m)*np.dot(X.T,error)
        b -= (a/m)*np.sum(error)
        
        if (i%10000 == 0):
            print(f"at {i} th iteration cost = {cost(X,y,w,b)}\n")
            
    return w,b


w_train,b_train= reg(X_norm,y_train,w_train,b_train,100000,0.01)
print(cost(X_norm,y_train,w_train,b_train))
# print(np.shape(w_train))



# ------------------------

def predict(X, w, b):
    return sigmoid(X, w, b) >= 0.5

# Create a grid of values
u = np.linspace(X_train[:, 0].min()-1, X_train[:, 0].max()+1, 500)
v = np.linspace(X_train[:, 1].min()-1, X_train[:, 1].max()+1, 500)
U, V = np.meshgrid(u, v)
UV_features = np.column_stack([U.ravel(), V.ravel()])

# Map features (same as training)
UV_poly = np.column_stack([
    UV_features[:, 0],
    UV_features[:, 1],
    UV_features[:, 0]**2,
    UV_features[:, 1]**2,
    UV_features[:, 0]*UV_features[:, 1],
    UV_features[:, 0]**3,
    UV_features[:, 1]**3
])

# Normalize with training data stats
UV_norm = (UV_poly - np.mean(X_final, axis=0)) / np.std(X_final, axis=0)

# Predict on grid
Z = predict(UV_norm, w_train, b_train).reshape(U.shape)

# Plot data
plt.scatter(X_train[y_train == 0][:, 0], X_train[y_train == 0][:, 1], c='red', label='Not admitted')
plt.scatter(X_train[y_train == 1][:, 0], X_train[y_train == 1][:, 1], c='blue', label='Admitted')

# Plot decision boundary
plt.contour(U, V, Z, levels=[0.5], linewidths=2, colors='green')
plt.xlabel('Exam 1 score')
plt.ylabel('Exam 2 score')
plt.legend()
plt.title('Decision Boundary')
plt.grid(True)
plt.show()

while True:
    x_in = np.array([int(input("x1: ")),int(input("x2: "))])
    x_int = np.array([x_in[0],x_in[1],x_in[0]**2,x_in[1]**2,x_in[0]*x_in[1],x_in[0]**3,x_in[1]**3])
    x_mean = np.mean(X_final,axis=0)
    x_std = np.std(X_final,axis=0)
    x_innorm = (x_int - x_mean) / x_std

    x_innorm = x_innorm.reshape(1, -1)

    ans = predict(x_innorm,w_train,b_train)
    print(int(ans))
