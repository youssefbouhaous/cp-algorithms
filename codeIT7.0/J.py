v="aeiouy"
while True:
    try:
        l=list(map(str,input().split()))
        c=0
        for i in l:
            for x in i:
                if x in v:
                    c+=1
        if c==2*len(l):
            print("NP")
        else:
            print("P")
    except:
        break
