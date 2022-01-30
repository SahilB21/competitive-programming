n = int(input())
cows = input()
lonelyPhotos = 0
hCount = 0
gCount = 0
substringLength = 3
for i in range(n-(substringLength-1)):
    substring = cows[i:i+substringLength]
    for i in range(len(substring)):
        if substring[i] == 'H':
            hCount += 1
        else:
            gCount += 1
    if hCount == 1 or gCount == 1:
        lonelyPhotos += 1
    gCount = 0
    hCount = 0
print(lonelyPhotos)
