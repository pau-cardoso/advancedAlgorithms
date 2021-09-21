def overtimeAmount(drivers, maxLength, payAmount):
    currentLength = 0
   
    routesMorning = [int(i) for i in input().split()]
    routesEvening = [int(i) for i in input().split()]
    routesMorning.sort(reverse=True)
    routesEvening.sort()
    
    for i in range(drivers):
        if maxLength < routesMorning[i]+routesEvening[i]:
            currentLength += (routesMorning[i]+routesEvening[i]) - maxLength
    
    return currentLength*payAmount



# Default code

f = open("output.txt", "w")
variables = input()
while variables != "0 0 0":
    n = int(variables.split()[0])
    d = int(variables.split()[1])
    r = int(variables.split()[2])
    print( overtimeAmount(n, d, r) )
    #f.write( str(overtimeAmount(n, d, r)) + "\n")
    
    variables = input()

f.close()