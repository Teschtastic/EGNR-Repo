/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 3                                                            *|
|* date: 9/24/18                                                            *|
|* purpose: Helps the user convert one type of length to another            *|
|*                                                                          *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>

/* ~ Protyping functions ~ */
int Get_First_Unit();
int Get_Second_Unit();
float Meter_Feet(float);
float Meter_Furlong(float);
float Feet_Meter(float);
float Feet_Furlong(float);
float Furlong_Meter(float);
float Furlong_Feet(float);
float Get_Feet();
float Get_Meter();
float Get_Furlong();

int main()
{
    /* ~ Declaring variables needed ~ */
    int ent_unit, conv_unit;
    float feet, meter, furlong, conv_meter, conv_feet, conv_furlong;
    
    /* ~ Getting user input for units ~ */
    ent_unit = Get_First_Unit();
    conv_unit = Get_Second_Unit();
    
    /* ~ Converting from meters ~ */
    if ((ent_unit == 1) && (conv_unit == 1))
    {
        /* ~ Meters to meters ~ */
        meter = Get_Meter();
        conv_meter = meter;
        printf("\n\t%.4f meters is %.4f meters\n", meter, conv_meter);
    }
    else if ((ent_unit == 1) && (conv_unit == 2))
    {
        /* ~ Meters to feet ~ */
        meter = Get_Meter();
        conv_feet = Meter_Feet(meter);
        printf("\n\t%.4f meters is %.4f feet\n", meter, conv_feet);
    }
    else if ((ent_unit == 1) && (conv_unit == 3))
    {
        /* ~ Meters to furlongs ~ */
        meter = Get_Meter();
        conv_furlong = Meter_Furlong(meter);
        printf("\n\t%.4f meters is %.4f furlongs\n", meter, conv_furlong);
    }
    
    /* ~ Converting from feet ~ */
    else if ((ent_unit == 2) && (conv_unit == 1))
    {
        /* ~ Feet to meters ~ */
        feet = Get_Feet();
        conv_meter = Feet_Meter(feet);
        printf("\n\t%.4f feet is %.4f meters\n", feet, conv_meter);
    }
    else if ((ent_unit == 2) && (conv_unit == 2))
    {
        /* ~ Feet to feet ~ */
        feet = Get_Feet();
        conv_feet = feet;
        printf("\n\t%.4f feet is %.4f feet\n", feet, conv_feet);
    }
    else if ((ent_unit == 2) && (conv_unit == 3))
    {
        /* ~ Feet to furlongs ~ */
        feet = Get_Feet();
        conv_furlong = Feet_Furlong(feet);
        printf("\n\t%.4f feet is %.4f furlongs\n", feet, conv_furlong);
    }
    
    /* ~ Converting from furlongs ~ */
    else if ((ent_unit == 3) && (conv_unit == 1))
    {
        /* ~ Furlongs to meters ~ */
        furlong = Get_Furlong();
        conv_meter = Furlong_Meter(furlong);
        printf("\n\t%.4f furlongs is %.4f meters\n", furlong, conv_meter);
    }
    else if ((ent_unit == 3) && (conv_unit == 2))
    {
        /* ~ Furlongs to feet ~ */
        furlong = Get_Furlong();
        conv_feet = Furlong_Feet(furlong);
        printf("\n\t%.4f furlongs is %.4f feet\n", furlong, conv_feet);
    }
    else if ((ent_unit == 3) && (conv_unit == 3))
    {
        /* ~ Furlongs to furlongs ~ */
        furlong = Get_Furlong();
        conv_furlong = furlong;
        printf("\n\t%.4f furlongs is %.4f furlongs\n", furlong, conv_furlong);
    }
    return 0;
}

/* ~ Getting the first unit from user ~ */
int Get_First_Unit()
{
    int unit;
    printf("Indicate entry unit \n(1 = meter, 2 = feet, 3 = furlong): ");
    scanf("%d", &unit);
    return unit;
}

/* ~ Getting the second input from the user ~ */
int Get_Second_Unit()
{
    int unit;
    printf("Indicate converted unit \n(1 = meter, 2 = feet, 3 = furlong): ");
    scanf("%d", &unit);
    return unit;
}

/* ~ Converts meters to feet ~ */
float Meter_Feet(float unit)
{
    return (unit * 3.28084);
}

/* ~ Converts meters to furlongs ~ */
float Meter_Furlong(float unit)
{
    return (unit * 0.00497096);
}

/* ~ Converts feet to meters ~ */
float Feet_Meter(float unit)
{
    return (unit * 0.3048);
}

/* ~ Converts feet to furlongs ~ */
float Feet_Furlong(float unit)
{
    return (unit * 0.00151515);
}
/* ~ Convert furlongs to meters ~ */
float Furlong_Meter(float unit)
{
    return (unit * 201.168);
}

/* ~ Converts furlongs to feet ~ */
float Furlong_Feet(float unit)
{
    return (unit * 660.001);
}

/* ~ Getting amount of feet from user ~ */
float Get_Feet ()
{
    float unit;
    printf("\n\tEnter distance in feet: ");
    scanf("%f", &unit);
    return unit;
}

/* ~ Getting amount of meters from user ~ */
float Get_Meter()
{
    float unit;
    printf("\n\tEnter distance in meters: ");
    scanf("%f", &unit);
    return unit;
}

/* ~ Getting amount of furlongs from user ~ */
float Get_Furlong()
{
    float unit;
    printf("\n\tEnter distance in furlongs: ");
    scanf("%f", &unit);
    return unit;
}
