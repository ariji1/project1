import glob, os, math

def freq(x):
        l = x.split("\n")
        remove = list('.,!@#$%^&*()-=+\/|"?><[]{}')
        s = []
        for i in l:
            m = i.split(" ")
            for k in m:
                y = k.lower()
                s.append(y)
        p = []
        for char in s:
            p.append(char.strip(str(remove)))
        a = {}
        for i in p:
            a[i] = p.count(i)
        #file.close()
        return a



def EuclideanNorm(a):
    s1=0
    for i in a.values():
        s1 += (i ** 2)
    return math.sqrt(s1)

def CalculateProbability(a,b):
    sum = 0
    for i in a.keys():
        for k in b.keys():
            if k == i:
                sum += int(b[k]) * int(a[i])
    return sum

os.chdir("D:/uyt")
for file in glob.glob("*.txt"):
    f = open(file)
    p = f.read()
    freq(p)

t=[]
path = os.chdir("D:/uyt")
t = [p for p in os.listdir(path) if p.endswith('.txt')]
print(t)

for i in range(0,len(t),1):
    for j in range(i+1,len(t),1):
        x=t[i]
        y=t[j]

        a = freq(x)
        s1 = EuclideanNorm(a)

        b = freq(y)
        s2 = EuclideanNorm(b)

        sum = CalculateProbability(a, b)
        print('Bag of Words')
        print('Probability of Files',x,y,':', (sum / (s1 * s2))*100)
        # print('String Matching')
        # StringMatching(x,y)
        print('')
















