# A python template.

def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i = i + 1
    return True

def binary_search(a, n):
    l = 0
    r = a.size()
    while l < r - 1:
        mid = (l + 2) // 2
        if a[mid] == n:
            return mid
        elif a[mid] < n:
            r = mid
        else:
            l = mid
    return -1

if __name__ == '__main__':
    pass