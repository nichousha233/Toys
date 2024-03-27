#!/usr/bin/python3
import numpy as np
#from numpy import linalg as LA
from scipy.linalg import eigh

N = 20
for i in range(1):

    a = np.loadtxt("Hp_Ek0/rank0")[:,1].reshape((N,N)).T
    b = np.loadtxt("Mp_Ek0/rank0")[:,1].reshape((N,N)).T
    z = np.loadtxt("Z_Ek0/rank0")[:,1].reshape((N,N)).T
    w = np.loadtxt("W_Ek0/rank0")[:,1].reshape((N))
    b = np.triu(b,1).T + np.triu(b,0)
    a = np.triu(a,1).T + np.triu(a,0)

    l, v = eigh(a,b, lower = False)

    max_diff_l_w = np.max(np.abs(l-w))
    vbv = v.T @ b @ v
    zbz = z.T @ b @ z
    vbv_I = vbv - np.identity(N)
    zbz_I = zbz - np.identity(N)
    print("max_diff_l_w = {}".format(max_diff_l_w))
    print(np.trace(vbv), np.trace(zbz))
    print(np.max(np.abs(vbv_I)), np.max(np.abs(zbz_I)))
    print('')

    #psi = np.loadtxt("Yorb_BLCYC_Ek0/rank0")[:,1].reshape((1000,N))
    psi = np.loadtxt("v_tilde_f_Ek0/rank0")[:,1].reshape((N, 1000)).T
    psiz = psi @ z
    print(psiz.shape)
    psiz2 = psiz * psiz
    print(np.sum(psiz2[:,:]))
    print('')

    #psi = np.loadtxt("Yorb_BLCYC_Ek0/rank0")[:,1].reshape((1000,N))
    psi = np.loadtxt("v_tilde_f_Ek0/rank0")[:,1].reshape((N, 1000)).T
    psiv = psi @ v
    print(psiv.shape)
    psiv2 = psiv * psiv
    print(np.sum(psiv2[:,:]))
    print('')

    psiz_out = np.loadtxt("v_tilde2_Ek0/rank0")[:,1].reshape((N, 1000)).T
    psiz_out2 = psiz_out * psiz_out
    print(np.sum(psiz_out2[:,:]))
    print('')

    psiQ = np.loadtxt("PsiQ/rank0")[:,1].reshape((N, 1000)).T
    psiQ2 = psiQ * psiQ

    div = psiQ - psiz
    print(np.max(np.abs(div)))
    print(np.sum(psiQ2))
    print(np.sum(psiz_out2))
