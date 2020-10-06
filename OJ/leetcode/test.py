# def solution(a,b):
#     if a>b:
#         return None
#     ans=[]
#     for i in range(a,b+1):
#         s=tmp=i
#         while i >0:
#             last=i%10
#             i=i//10
#             tmp-=pow(last,3)
#         if tmp==0:
#             ans.append(s)  
    
#     return ans
# import os
# import sys
# def testPath():
#     print(os.path.dirname(__file__))
#     print(os.path.dirname(sys.argv[0]))    #输出当前程序所在的目录。如果以相对路径执行，则输出为空目录（空字符串）。
#     print(sys.argv[0])     #输出程序本身位置
#     print(sys.argv[1])     #输出程序参数。如python test.py can 则输出can
# def reverse():
#     an=[1,2,3,4,5,6,7,8]
#     print(an[::-1])

test = [[0]*3 for j in range(4)]
print(test)
