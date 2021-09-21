#host guest
def guestUniform():
    n=0
    host =[]
    guest = []
    for i in range(int(input())):
        r = input().split()
        currentH =r[0]
        currentG = r[1]
        host.append(currentH)
        guest.append(currentG)
        if(currentH in guest):
            n+=1
        if(currentG in host):
            n+=1
        

    return n


print(guestUniform())