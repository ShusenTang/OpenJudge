#include <cstdio>

char s[10];

int main()
{
    //freopen("input.txt","r",stdin);
    int t, n;
    //三维物体至少需要两个方向才能确定具体方向，即水平(face)和垂直(ver)
    int x, y, z, face, left, ver, temp, d; //ver:vertical,代表头的朝向
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        x = y = z = 0;
        face = 0, left = 4, ver = 2;
        while (n--)
        {
            scanf("%s %d", s, &d);
            if (s[0] == 'b')  face = (face + 3) % 6, left = (left + 3) % 6;
            else if (s[0] == 'l')  temp = face, face = left, left = (temp + 3) % 6;
            else if (s[0] == 'r')  temp = left, left = face, face = (temp + 3) % 6;
            else if (s[0] == 'u')  temp = face, face = ver, ver = (temp + 3) % 6;
            else if (s[0] == 'd')  temp = ver, ver = face, face = (temp + 3) % 6;
            if (face == 0)  x += d;
            else if (face == 1)  y += d;
            else if (face == 2)  z += d;
            else if (face == 3)  x -= d;
            else if (face == 4)  y -= d;
            else  z -= d; ///face == 5
        }
        printf("%d %d %d %d\n", x, y, z, face);
    }
    return 0;
}

