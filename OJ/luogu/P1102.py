def binarySearch(goal, source):
    left = 0
    right = len(source)-1
    while left <= right:
        mid = (left+right)//2
        if source[mid] > goal:
            right = mid-1
        elif source[mid] < goal:
            left = mid+1
        else:
            return mid
    return -1

def solution(nums, target):
    from collections import Counter
    h = Counter(nums)
    n=0
    for num in nums:
        if target+num in h:
            n+=h[target+num]
    return n


if __name__ == "__main__":
    n, c = map(int, input().split())
    source = list(map(int, input().split()))
    print(solution(source,c))
    # source.sort()
    # num = 0
    # for b in source:
    #     goal = b+c
    #     index = binarySearch(goal, source)
    #     if index != -1:
    #         num += 1
    #         lindex = rindex = index
    #         while lindex > 0 and source[lindex] == source[lindex-1]:
    #             lindex -= 1
    #             num += 1
    #         while rindex < len(source)-1 and source[rindex] == source[rindex+1]:
    #             rindex += 1
    #             num += 1
    # print(num)


