if __name__ == "__main__":
    """
  map()第一个参数接受一个函数名，后面的参数接受一个或多个可迭代的序列，返回的是一个集合。 
Python函数编程中的map()函数是将func作用于seq中的每一个元素，并将所有的调用的结果作为一个list返回。
    """
    start,end=map(int,input().split())
    
    f=[0]+[1]*(end-start+1)
    for i in range(3,end-start+2):
        f[i]=f[i-1]+f[i-2]
    print(f[end-start+1])