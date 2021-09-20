from collections import Counter

try:
    str = input()
    pattern = input()
    k = len(pattern)
    ans = 0
    dct = Counter(list(pattern))
    count = len(dct)
    j = 0 
    for i in range(len(str)):
        if dct.get(str[i]) is not None:
            dct[str[i]] -= 1
            if dct[str[i]] == 0:
                count -= 1
        if (i-j+1) == k:
            if count == 0:
                ans += 1
            if dct.get(str[j]) is not None:
                dct[str[j]] += 1
                if dct[str[j]] == 1:
                    count += 1
            j += 1

    print(ans)

except Exception as e:
    print(e)
