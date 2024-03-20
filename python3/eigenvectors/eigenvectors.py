#!/usr/local/bin/python3.9
import numpy as np
#from numpy import linalg as LA
from scipy.linalg import eigh

N = 1600
for i in range(6):
    a = np.loadtxt('DEBUG1/a{}/rank0a.txt'.format(i)).reshape((N,N))
    b = np.loadtxt('DEBUG1/b{}/rank0b.txt'.format(i)).reshape((N,N))
    z = np.loadtxt('DEBUG1/z{}/rank0z.txt'.format(i)).reshape((N,N))

    w, v = eigh(a,b)
    diff = v[:,0] - z[:,0]
    add = v[:,0] + z[:,0]
    np.savetxt('w{}.txt'.format(i), w)
    np.savetxt('diff{}.txt'.format(i), diff)
    np.savetxt('add{}.txt'.format(i), add)
    np.savetxt('z0{}.txt'.format(i), z[:,0])
    np.savetxt('v0{}.txt'.format(i), v[:,0])
