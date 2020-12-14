import numpy as np
import time


def power_eng(A, n):
    A = np.array(A)
    x = np.random.rand(n, 1)
    for i in range(30 * n * n):
        x = A.dot(x)
        # 归一化
        x = x / np.linalg.norm(x)
    env = x
    pld = x.T.dot(A).dot(x) / x.T.dot(x)
    return pld,env


def jacobi_eng(A, n):
    esp = 1e-10
    u = np.array(A)
    v = np.identity(n)
    for num in range(30 * n * n):
        # 在非对角线上找到最大的元素
        max_row = 0
        max_col = 0
        max = 0
        for i in range(n):
            for j in range(n):
                if i != j and abs(u[i, j]) > max:
                    max = abs(u[i, j])
                    max_row = i
                    max_col = j
        if max < esp:
            break
        u_ii = u[max_row, max_row]
        u_ij = u[max_row, max_col]
        u_jj = u[max_col, max_col]

        # 计算旋转角度
        theta = 0.5 * np.arctan2(-2 * u_ij, u_jj - u_ii)
        sin_theta = np.sin(theta)
        cos_theta = np.cos(theta)
        # 旋转矩阵
        J = np.zeros((n, n))
        for i in range(n):
            J[i, i] = 1
        J[max_row, max_row] = cos_theta
        J[max_col, max_col] = cos_theta
        J[max_row, max_col] = -sin_theta
        J[max_col, max_row] = sin_theta
        # 迭代
        u = J.T.dot(u).dot(J)
        # 记录下特征向量
        v = v.dot(J)
    # 返回特征值
    return u


# shifted QR
def qr(A, n):
    kounttol = 500
    ev = np.zeros((1, n), dtype=complex)
    A = np.array(A)
    while n > 1:
        kount = 0
        max = 0
        # 第n行最大的元素
        for i in range(n - 1):
            if abs(A[n - 1, i]) > max:
                max = abs(A[n - 1, i])
        while kount < kounttol and max > 1e-10:
            kount += 1
            mu = A[n - 1, n - 1]
            Q, R = np.linalg.qr(A - mu * np.identity(n))
            A = R.dot(Q) + mu * np.identity(n)
            max = 0
            for i in range(n - 1):
                if abs(A[n - 1, i]) > max:
                    max = abs(A[n - 1, i])
        # 具有分离的1*1的块
        if kount < kounttol:
            ev[0, n - 1] = A[n - 1, n - 1]
            A = np.delete(A, n - 1, axis=0)
            A = np.delete(A, n - 1, axis=1)
            n -= 1
        else:
            disc = (A[n - 2, n - 2] - A[n - 1, n - 1]) * (A[n - 2, n - 2] - A[n - 1, n - 1]) + 4 * A[n - 1, n - 2] * A[
                n - 2, n - 1]
            ev[0, n - 1] = (A[n - 2, n - 2] + A[n - 1, n - 1] +
                            np.sqrt(complex(disc))) / 2
            ev[0, n - 2] = (A[n - 2, n - 2] + A[n - 1, n - 1] -
                            np.sqrt(complex(disc))) / 2
            A = np.delete(A, n - 1, axis=0)
            A = np.delete(A, n - 1, axis=1)
            A = np.delete(A, n - 2, axis=0)
            A = np.delete(A, n - 2, axis=1)
            n = n - 2
    if n > 0:
        ev[0, 0] = A[0, 0]
    return ev

# hessenberg变换加速求解
def gauss_hessen(A):
    [row, column] = np.shape(A)
    k = 0
    while k < (column - 2):
        J = np.eye(row)
        x = A[:, k][k + 1]
        if x != 0:
            for i in range(row - (k + 2)):
                A = -(A[:, k][k + 2 + i] / x)
                J[(k + 2 + i)][(k + 1)] = A
            A = J.dot(A).dot(np.linalg.inv(J))
        else:
            col= A[:, k]
            cur = k + 2
            while cur < row:
                if (col[cur] != 0):
                    A[[k + 1, cur], :] = A[[cur, k + 1], :]
                    A[:[k + 1, cur]] = A[:[cur, k + 1]]
                    for i in range(row - (k + 2)):
                        A = -(A[:, k][k + 2 + i] / x)
                        J[(k + 2 + i)][(k + 1)] = A
                    A = J.dot(A).dot(np.linalg.inv(J))
                    break
                cur += 1
        k += 1
    return A


def qr_eng(A, n):
    A = gauss_hessen(A, n)
    return qr(A, n)

def test(M,name):
    time1 = time.time()
    pld,env=power_eng(M,len(M))
    time2 = time.time()
    print("幂:"+name+"用时"+time2-time1)
    print("pld:\n", pld)
    print("env:\n", env)

    time1 = time.time()
    ev=jacobi_eng(M,len(M))
    time1 = time.time()
    print("jacobi:"+name+"用时"+time2-time1)
    print("ev:\n", ev)

    time1 = time.time()
    ev=qr_eng(M,len(M))
    time1 = time.time()
    print("qr:"+name+"用时"+time2-time1)
    print("ev:\n", ev)

if __name__ == "__main__":
    A = [
        [611, 196, -192, 407, -8, -52, -49, 29],
        [196, 899, 113, -192, -71, -43, -8, -44],
        [-192, 113, 899, 196, 61, 49, 8, 52],
        [407, -192, 196, 611, 8, 44, 59, -23],
        [-8, -71, 61, 8, 411, -599, 208, 208],
        [-52, -43, 49, 44, -599, 411, 208, 208],
        [-49, -8, 8, 59, 208, 208, 99, -911],
        [29, -44, 52, -23, 208, 208, -911, 99]
    ]
    B = [
        [1 / 1.0, 1 / 2.0, 1 / 3.0, 1 / 4.0, 1 / 5.0,
            1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0],
        [1 / 2.0, 1 / 3.0, 1 / 4.0, 1 / 5.0, 1 / 6.0, 1 /
            7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0],
        [1 / 3.0, 1 / 4.0, 1 / 5.0, 1 / 6.0, 1 / 7.0, 1 /
            8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0],
        [1 / 4.0, 1 / 5.0, 1 / 6.0, 1 / 7.0, 1 / 8.0, 1 /
            9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0],
        [1 / 5.0, 1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0, 1 /
            10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0],
        [1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 /
            11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0, 1 / 15.0],
        [1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 /
            12.0, 1 / 13.0, 1 / 14.0, 1 / 15.0, 1 / 16.0],
        [1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 /
            13.0, 1 / 14.0, 1 / 15.0, 1 / 16.0, 1 / 17.0],
        [1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0,
            1 / 14.0, 1 / 15.0, 1 / 16.0, 1 / 17.0, 1 / 18.0],
        [1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0,
            1 / 15.0, 1 / 16.0, 1 / 17.0, 1 / 18.0, 1 / 19.0]
    ]
    C = [
        [12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [11, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [9, 9, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [8, 8, 8, 8, 8, 7, 6, 5, 4, 3, 2, 1],
        [7, 7, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1],
        [6, 6, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1],
        [5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1],
        [4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1],
        [3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1],
        [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    ]
    A = np.array(A)
    B = np.array(B)
    C = np.array(C)
    D = np.zeros((20, 20))
    for i in range(20):
        for j in range(20):
            D[i, j] = np.sqrt(2 / 21) * np.sin((i + 1) *
                                               (j + 1) * np.pi / 21)

    E = np.zeros((50, 50))
    for i in range(50):
        for j in range(50):
            if j < i:
                E[i, j] = -1
            elif j == i or j == 49:
                E[i, j] = 1
            else:
                E[i, j] = 0
    A = [[2, 1], [1, 2]]

    test(A)
    test(B)
    test(C)
    test(D)
    test(E)

    # 解方程
    F = [
        [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
    ]
    ev=qr_eng(F, len(F))
    print(ev)




