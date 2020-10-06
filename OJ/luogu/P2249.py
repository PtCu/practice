def binarySearch(goal,source):
    left=0;right=len(source)-1
    while left<=right:
        mid=(left+right)//2
        if source[mid]>goal:
            right=mid-1
        elif source[mid]<goal:
            left=mid+1
        else: 
            return mid 
    return -1
if __name__ == "__main__":
    n,m=map(int,input().split())
    source=list(map(int,input().split()))
    destination=list(map(int,input().split()))
    index=0
    for goal in range(len(destination)):
        index=binarySearch(destination[goal],source)
        if index==-1:
            print(str(index)+" ",end="")
        else:
            while destination[goal]==source[index]:
                index-=1
            print(str(index+2)+" ",end="")
    
                
