def flea(n, m , s):
    minim = n
    maxim = m
    if n > m: 
        minim = m
        maxim = n
    if maxim <= s or s==1 or (n%s == 0 and m%s == 0):
        return n*m
    checkJumpsN = ((n-1)//s)+1
    checkJumpsM = ((m-1)//s)+1
    return checkJumpsN*(((n-1)%s)+1)*checkJumpsM*(((m-1)%s)+1)


# Default code
usrInput = input().split()
n = int(usrInput[0])
m = int(usrInput[1])
s = int(usrInput[2])
print(flea(n, m, s))
