//
//  main.c
//  Alarm
//
//  Created by Sean Tesch on 9/11/18.
//  Copyright © 2018 Sean Tesch. All rights reserved.
//

#include <stdio.h>

void beeper()
{
    printf("\a");
    beeper();
    return;
}

int main()
{
    beeper();
    return 0;
}
