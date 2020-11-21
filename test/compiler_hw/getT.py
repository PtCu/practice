import re
f=open("1.txt")
t=f.read()
f.close()
pattern=re.compile("`([^`]*)`")
result=pattern.findall(t)
f=open("2.txt","w")
result_wait_to_write = '\n'.join(result)   
#在result这个列表的每个元素间，用换行符\n拼接成单独一个字符串

f.write(result_wait_to_write)    #写入文件
f.close()                        #关闭文件
