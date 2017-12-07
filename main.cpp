#include "mbed.h"
#include "PololuLedStrip.h"
#include "main.h"

void setup()
{
    int i, j;
    for(i = 0; i < LED_COUNT; i++)
        off[i] = (rgb_color) {0,0,0};
    
    i = 0;
    j = 0;
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < LED_COUNT; j++)
        {
                if(maskzero[i][j] == 1)
                    zero[i][j] = (rgb_color) {255 & color,0,255};
                else
                    zero[i][j] = (rgb_color) {0,0,0};
                    
                if(maskone[i][j] == 1)
                    one[i][j] = (rgb_color) {255 & color,0,255};
                else
                    one[i][j] = (rgb_color) {0,0,0};
                    
                if(masktwo[i][j] == 1)
                    two[i][j] = (rgb_color) {255 & color,0,255};
                else
                    two[i][j] = (rgb_color) {0,0,0};
                    
                if(maskthree[i][j] == 1)
                    three[i][j] = (rgb_color) {255 & color,0,255};
                else
                    three[i][j] = (rgb_color) {0,0,0};
                    
                if(maskfour[i][j] == 1)
                    four[i][j] = (rgb_color) {255 & color,0,255};
                else
                    four[i][j] = (rgb_color) {0,0,0};
                    
                if(maskfive[i][j] == 1)
                    five[i][j] = (rgb_color) {255 & color,0,255};
                else
                    five[i][j] = (rgb_color) {0,0,0};
                    
                if(masksix[i][j] == 1)
                    six[i][j] = (rgb_color) {255 & color,0,255};
                else
                    six[i][j] = (rgb_color) {0,0,0};
                    
                if(maskseven[i][j] == 1)
                    seven[i][j] = (rgb_color) {255 & color,0,255};
                else
                    seven[i][j] = (rgb_color) {0,0,0};
                    
                if(maskeight[i][j] == 1)
                    eight[i][j] = (rgb_color) {255 & color,0,255};
                else
                    eight[i][j] = (rgb_color) {0,0,0};
                    
                if(masknine[i][j] == 1)
                    nine[i][j] = (rgb_color) {255 & color,0,255};
                else
                    nine[i][j] = (rgb_color) {0,0,0};
        }
    }
}

void writezero()
{
    int i;
    for(i = 0; i < WIDTH; i++)
    {
        ledStrip.write(zero[i], LED_COUNT);
        wait_ms(1);
    }
}

void writeone()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(one[i], LED_COUNT);
            wait_ms(1);
        }
}

void writetwo()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(two[i], LED_COUNT);
            wait_ms(1);
        }
}

void writethree()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(three[i], LED_COUNT);
            wait_ms(1);
        }
}

void writefour()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(four[i], LED_COUNT);
            wait_ms(1);
        }
}

void writefive()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(five[i], LED_COUNT);
            wait_ms(1);
        }
}

void writesix()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(six[i], LED_COUNT);
            wait_ms(1);
        }
}

void writeseven()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(seven[i], LED_COUNT);
            wait_ms(1);
        }
}

void writeeight()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(eight[i], LED_COUNT);
            wait_ms(1);
        }
}

void writenine()
{
    int i;
    for(i = 0; i < WIDTH; i++)
        {
            ledStrip.write(nine[i], LED_COUNT);
            wait_ms(1);
        }
}

void tock()
{
    minute++;
    hour += minute % 59;
    hour %= 24;
    minute %= 60;
}

void changecolor()
{
    if(color == 0)
        color = 255;
    else
        color = 0;
        
    setup();
}

void speedup()
{
    if(speed > 5)
        speed -= 10;
    wait_ms(1);
}

void slowdown()
{
    if(speed < 500)
        speed += 10;
    wait_ms(1);
}

int main()
{
    setup();
    speed = 15;
    minute = 0;
    hour = 8;
    button2.rise(&changecolor);
    button3.rise(&speedup);
    button4.rise(&slowdown);
    tick.attach(&tock, 60);
    
    while(1)
    {
        switch(minute % 10)
        {
        case 0:
            writezero();
            break;
        case 1:
            writeone();
            break;
        case 2:
            writetwo();
            break;
        case 3:
            writethree();
            break;
        case 4:
            writefour();
            break;
        case 5:
            writefive();
            break;
        case 6:
            writesix();
            break;
        case 7:
            writeseven();
            break;
        case 8:
            writeeight();
            break;
        case 9:
            writenine();
            break;
        }
        
        ledStrip.write(off, LED_COUNT);
        wait_ms(2);
        
        switch(minute / 10)
        {
        case 0:
            writezero();
            break;
        case 1:
            writeone();
            break;
        case 2:
            writetwo();
            break;
        case 3:
            writethree();
            break;
        case 4:
            writefour();
            break;
        case 5:
            writefive();
            break;
        case 6:
            writesix();
            break;
        case 7:
            writeseven();
            break;
        case 8:
            writeeight();
            break;
        case 9:
            writenine();
            break;
        }
        
        ledStrip.write(off, LED_COUNT);
        wait_ms(2);
        
        switch(hour % 10)
        {
        case 0:
            writezero();
            break;
        case 1:
            writeone();
            break;
        case 2:
            writetwo();
            break;
        case 3:
            writethree();
            break;
        case 4:
            writefour();
            break;
        case 5:
            writefive();
            break;
        case 6:
            writesix();
            break;
        case 7:
            writeseven();
            break;
        case 8:
            writeeight();
            break;
        case 9:
            writenine();
            break;
        }
        
        ledStrip.write(off, LED_COUNT);
        wait_ms(2);
        
        switch(hour / 10)
        {
        case 0:
            writezero();
            break;
        case 1:
            writeone();
            break;
        case 2:
            writetwo();
            break;
        case 3:
            writethree();
            break;
        case 4:
            writefour();
            break;
        case 5:
            writefive();
            break;
        case 6:
            writesix();
            break;
        case 7:
            writeseven();
            break;
        case 8:
            writeeight();
            break;
        case 9:
            writenine();
            break;
        }
        
        ledStrip.write(off, LED_COUNT);
        wait_ms(speed);
    }
}