#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main()
{
    FAST
        string t;
    while (true)
    {
        cin >> t;
        if(t=="END")break;
        int hour = 0, minute = 0;
        bool chk = false;
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == ':')
            {
                chk = true;
            }
            else
            {
                if (!chk)
                {
                    hour *= 10;
                    hour += t[i] - '0';
                }
                else
                {

                    minute *= 10;
                    minute += t[i] - '0';
                }
            }
        }
        double pi = 4 * atan(1);

        double minuteAngleOriginal = minute * 6;
        double hourAngleOriginal = hour * 30 + minute * 0.5;
        double minuteAngleConv = fmod((-minuteAngleOriginal + 90) + 720, 360);
        double hourAngleConv = fmod((-hourAngleOriginal + 90) + 720, 360);
        double minRad = pi / 180 * minuteAngleConv;
        double hourRad = pi / 180 * hourAngleConv;
        int base = 25;
        char minuteHand[51][51];
        char hourHand[43][43];
        memset(minuteHand, 0, sizeof(minuteHand));
        memset(hourHand, 0, sizeof(hourHand));

        if ((hourAngleConv >= 45 && hourAngleConv <= 135))
        {
            //y-based index1

            for (int i = -1; i > -15; i--)
            {
                //be careful of the signs
                int prev = round(1 / tan(hourRad) * (i + 1));
                int now = round(1 / tan(hourRad) * i);
                int next = round(1 / tan(hourRad) * (i - 1));
                char &ch = minuteHand[base + i][base - now];
                if (prev == now && now == next)
                {
                    ch = '|';
                }
                else if (prev - now == 1 && now - next == 1)
                {
                    ch = '/';
                }
                else if (prev - now == -1 && now - next == -1)
                {
                    ch = '\\';
                }
                else
                {
                    ch = 'o';
                }
            }
        }
        else if (hourAngleConv >= 225 && hourAngleConv <= 315)
        {
            //y-based index2
            for (int i = 1; i < 15; i++)
            {
                int prev = round(1 / tan(hourRad) * (i - 1));
                int now = round(1 / tan(hourRad) * i);
                int next = round(1 / tan(hourRad) * (i + 1));
                char &ch = minuteHand[base + i][base - now];
                if (prev == now && now == next)
                {
                    ch = '|';
                }
                else if (prev - now == 1 && now - next == 1)
                {
                    ch = '\\';
                }
                else if (prev - now == -1 && now - next == -1)
                {
                    ch = '/';
                }
                else
                {
                    ch = 'o';
                }
            }
        }
        else
        {
            //x-based index
            if ((hourAngleConv >= 0 && hourAngleConv <= 45) || (hourAngleConv >= 315 && hourAngleConv <= 360))
            {
                for (int i = 1; i < 15; i++)
                {
                    int prev = round(tan(hourRad) * (i - 1));
                    int now = round(tan(hourRad) * i);
                    int next = round(tan(hourRad) * (i + 1));
                    char &ch = minuteHand[base - now][base + i];

                    if (prev == now && now == next)
                    {
                        ch = '-';
                    }
                    else if (prev - now == 1 && now - next == 1)
                    {
                        ch = '\\';
                    }
                    else if (prev - now == -1 && now - next == -1)
                    {
                        ch = '/';
                    }
                    else
                    {
                        ch = 'o';
                    }
                }
            }
            else
            {
                for (int i = 1; i > -15; i--)
                {
                    int prev = round(tan(hourRad) * (i + 1));
                    int now = round(tan(hourRad) * i);
                    int next = round(tan(hourRad) * (i - 1));
                    char &ch = minuteHand[base - now][base + i];

                    if (prev == now && now == next)
                    {
                        ch = '-';
                    }
                    else if (prev - now == 1 && now - next == 1)
                    {
                        ch = '/';
                    }
                    else if (prev - now == -1 && now - next == -1)
                    {
                        ch = '\\';
                    }
                    else
                    {
                        ch = 'o';
                    }
                }
            }
        }
        if ((minuteAngleConv >= 45 && minuteAngleConv <= 135))
        {
            //y-based index1

            for (int i = -1; i > -21; i--)
            {
                //be careful of the signs
                int prev = round(1 / tan(minRad) * (i + 1));
                int now = round(1 / tan(minRad) * i);
                int next = round(1 / tan(minRad) * (i - 1));
                char &ch = minuteHand[base + i][base - now];
                if (prev == now && now == next)
                {
                    ch = '|';
                }
                else if (prev - now == 1 && now - next == 1)
                {
                    ch = '/';
                }
                else if (prev - now == -1 && now - next == -1)
                {
                    ch = '\\';
                }
                else
                {
                    ch = 'o';
                }
            }
        }
        else if (minuteAngleConv >= 225 && minuteAngleConv <= 315)
        {
            //y-based index2
            for (int i = 1; i < 21; i++)
            {
                int prev = round(1 / tan(minRad) * (i - 1));
                int now = round(1 / tan(minRad) * i);
                int next = round(1 / tan(minRad) * (i + 1));
                char &ch = minuteHand[base + i][base - now];
                if (prev == now && now == next)
                {
                    ch = '|';
                }
                else if (prev - now == 1 && now - next == 1)
                {
                    ch = '\\';
                }
                else if (prev - now == -1 && now - next == -1)
                {
                    ch = '/';
                }
                else
                {
                    ch = 'o';
                }
            }
        }
        else
        {
            //x-based index
            if ((minuteAngleConv >= 0 && minuteAngleConv <= 45) || (minuteAngleConv >= 315 && minuteAngleConv <= 360))
            {
                for (int i = 1; i < 21; i++)
                {
                    int prev = round(tan(minRad) * (i - 1));
                    int now = round(tan(minRad) * i);
                    int next = round(tan(minRad) * (i + 1));
                    char &ch = minuteHand[base - now][base + i];

                    if (prev == now && now == next)
                    {
                        ch = '-';
                    }
                    else if (prev - now == 1 && now - next == 1)
                    {
                        ch = '\\';
                    }
                    else if (prev - now == -1 && now - next == -1)
                    {
                        ch = '/';
                    }
                    else
                    {
                        ch = 'o';
                    }
                }
            }
            else
            {
                for (int i = 1; i > -21; i--)
                {
                    int prev = round(tan(minRad) * (i + 1));
                    int now = round(tan(minRad) * i);
                    int next = round(tan(minRad) * (i - 1));
                    char &ch = minuteHand[base - now][base + i];

                    if (prev == now && now == next)
                    {
                        ch = '-';
                    }
                    else if (prev - now == 1 && now - next == 1)
                    {
                        ch = '/';
                    }
                    else if (prev - now == -1 && now - next == -1)
                    {
                        ch = '\\';
                    }
                    else
                    {
                        ch = 'o';
                    }
                }
            }
        }
        minuteHand[base][base] ='*';
        minuteHand[2][base-1] = '1';
        minuteHand[2][base+1] = '2';
        minuteHand[48][base] = '6';
        minuteHand[base][2] = '9';
        minuteHand[base][48] = '3';
        for (int i = 0; i < 51; i++)
        {
            if(i==0||i==50){
                for (int j = 0; j < 51; j++)
                {
                    if(j%10==0)minuteHand[i][j] = '@';
                    else minuteHand[i][j] = 'X';
                }
                
                
            }
            else if(i%10==0){
                minuteHand[i][0] = '@';
                minuteHand[i][50] = '@';
            }
            else{

                minuteHand[i][0] = 'X';
                minuteHand[i][50] = 'X';
            }
            for (int j = 0; j < 51; j++)
            {
                
                if (minuteHand[i][j] == 0)
                    cout << ' ';
                else
                    cout << minuteHand[i][j];
            }
            cout << endl;
        }
        cout<<endl;
    }
}