def coinsNeeded(n, coins):
    currentTotal, count = 0, 0
    totalCoins = sum(coins)
    limit = int(totalCoins/2)

    for coin in coins:
        if limit < currentTotal:
            break
        else:
            currentTotal += coin
            count += 1
    
    return count


# Default code
n = input()
coins = input().split()
coins = [int(i) for i in coins]
coins.sort(reverse=True)

print(coinsNeeded(n, coins))