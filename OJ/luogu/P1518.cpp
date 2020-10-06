#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int maxnS = 1e5;
typedef enum
{
    north,
    east,
    south,
    west,
} Direction;
char _map[maxn + 2][maxn + 2];
Direction rotate(Direction &e)
{
    switch (e)
    {
    case north:
        e = east;
        break;
    case east:
        e = south;
        break;
    case south:
        e = west;
        break;
    case west:
        e = north;
        break;
    default:
        break;
    }
    return e;
}

struct Object
{
    int x;
    int y;
    Direction direction;
    void step()
    {
        switch (direction)
        {
        case east:
        {
            swap(_map[x][y], _map[x][y + 1]);
            y += 1;
        }

        break;
        case west:
        {
            swap(_map[x][y], _map[x][y - 1]);
            y -= 1;
        }

        break;
        case north:
        {
            swap(_map[x][y], _map[x - 1][y]);
            x -= 1;
        }

        break;
        case south:
        {
            swap(_map[x][y], _map[x + 1][y]);
            x += 1;
        }
        break;
        default:
            break;
        }
    }
};

bool hasObs(int x, int y)
{
    if (_map[x][y] == '*')
        return true;
    return false;
}
//下一步有障碍物返回false，否则返回true
bool prob(const Object obj)
{
    bool isOk = true;
    int x = obj.x;
    int y = obj.y;
    switch (obj.direction)
    {
    case east:
        if (hasObs(x, y + 1))
            isOk = false;
        break;
    case west:
        if (hasObs(x, y - 1))
            isOk = false;
        break;
    case north:
        if (hasObs(x - 1, y))
            isOk = false;
        break;
    case south:
        if (hasObs(x + 1, y))
            isOk = false;
        break;
    default:
        break;
    }
    return isOk;
}

//物体前进一格,不能移动返回false
void step(Object &obj)
{

    Direction origin = obj.direction; //探测四个方向
    do                                //for循环中，第一个;前会执行一次，然后判断第二个;前的表达式，如果为true则执行循环体，否则退出
    {
        if (prob(obj)) //如果该方向没障碍
        {
            obj.step(); //前进
            break;
        }
        else
        {
            rotate(obj.direction);
            break;
        }

    } while (origin != obj.direction);
}
//C和F是否相遇
bool isEncounter(const Object C, const Object F)
{
    if (C.x == F.x && C.y == F.y)
        return true;
    return false;
}

ofstream f("record.txt");
void print()
{
    for (int i = 0; i < maxn + 2; i++)
    {
        for (int j = 0; j < maxn + 2; j++)
            f << _map[i][j];
        f << endl;
    }
    f << endl;
}
int main()
{
    Object C, F;
    string s;
    stringstream ss;
    for (int i = 0; i < 12; i++)
    {
        _map[i][maxn + 1] = '*';
        _map[i][0] = '*';
    }
    for (int i = 0; i < 12; i++)
    {
        _map[0][i] = '*';
        _map[maxn + 1][i] = '*';
    }

    for (int i = 1; i < 11; i++)
    {
        ss.clear(); //如果打算在多次转化中使用同一个sstream，记得要clear
        getline(cin, s);
        ss.str(s);
        for (int j = 1; j < 12; j++)
        {
            ss >> _map[i][j];
            if (_map[i][j] == 'F')
            {
                F.x = i;
                F.y = j;
                F.direction = north;
            }
            else if (_map[i][j] == 'C')
            {
                C.x = i;
                C.y = j;
                C.direction = north;
            }
        }
    }
    int t = 0;

    for (;;)
    {
        if (isEncounter(C, F))
            break;
        t++;
        f << "t=" << t << endl;
        step(C);
        step(F);
        print();

        if (t > maxnS)
        {
            t = 0;
            break;
        }
    }
    cout << t;
}