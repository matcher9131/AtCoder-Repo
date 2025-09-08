from math import gcd, ceil
class LDE:
    #初期化
    def __init__(self,a,b,c):
        self.a,self.b,self.c=a,b,c
        self.m,self.x,self.y=0,[0],[0]
        #解が存在するか
        self.check=True
        g=gcd(self.a,self.b)
        if c%g!=0:
            self.check=False
        else:
            #ax+by=gの特殊解を求める
            self.extgcd(abs(self.a),abs(self.b),self.x,self.y)
            if a<0:self.x[0]=-self.x[0]
            if b<0:self.y[0]=-self.y[0]
            #ax+by=cの特殊解を求める
            self.x=self.x[0]*c//g
            self.y=self.y[0]*c//g
            #一般解を求めるために
            self.a//=g
            self.b//=g

    #拡張ユークリッドの互除法
    #返り値:aとbの最大公約数
    def extgcd(self,a,b,x0,y0):
        if b==0:
            x0[0],y0[0]=1,0
            return a
        d=self.extgcd(b,a%b,y0,x0)
        y0[0]-=(a//b)*x0[0]
        return d

    #パラメータmの更新(書き換え)
    def m_update(self,m):
        self.x+=(m-self.m)*self.b
        self.y-=(m-self.m)*self.a
        self.m=m

[a, b] = list(map(int, input().split()))
if a == 0:
    if abs(b) == 2:
        print("1 0")
    elif abs(b) == 1:
        print("2 0")
    else:
        print(-1)
    exit(0)
elif b == 0:
    if abs(a) == 2:
        print("0 1")
    elif abs(a) == 1:
        print("0 2")
    else:
        print(-1)
    exit(0)

lde = LDE(b, -a, 2)
if not lde.check:
    print(-1)
    exit(0)
if lde.y < -1e18:
    lde.m_update(ceil((-1e18 - lde.y) / lde.a))
    if abs(lde.x) > 1e18:
        print(-1)
        exit(0)
elif lde.y > 1e18:
    lde.m_update(ceil((lde.y - 1e18) / lde.a))
    if abs(lde.x) > 1e18:
        print(-1)
        exit(0)
print(f"{lde.x} {lde.y}")
