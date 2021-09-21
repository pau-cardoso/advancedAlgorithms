def uniformChanges(games, n):
    cont = 0
    for i in range(int(n)):
        for j in range(int(n)):
            if i == j: continue
            elif games[i][0] == games[j][1]:
                cont = cont+1
    return cont

# Default code
n = input()
games = []
for i in range(int(n)):
    teamColors = input()
    teamColors = teamColors.split()
    teamColors = [int(i) for i in teamColors]
    games.append(teamColors)

print(str(uniformChanges(games, n)))