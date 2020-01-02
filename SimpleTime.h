// Time class for basic time related functions

#ifndef SIMPLETIME_H
#define SIMPLETIME_H

#include <Arduino.h>

class SimpleTime
{
    private:
        int _hours;
        int _minutes;
        int _seconds;

        void _rollover(void);

    public:
        /*
         * Empty constructor.  Create a Time object at 00:00.00
         */
        SimpleTime(void);

        /* 
         * Constructor. Create time object and set the time to hours, minutes seconds
         */
        SimpleTime(int hours, int minutes, int seconds);

        /* 
         * Set the time to the passed hours, minutes and seconds
         */
        void set(int hours, int minutes, int seconds);
        
        /* 
         * Returns the current hours
         */
        int getHours(void);

        /* 
         * Returns the current minutes
         */
        int getMinutes(void);

        /* 
         * Returns the current seconds
         */
        int getSeconds(void);

        /* 
         * Add one second
         */
        void tick(void);

        /* 
         * Add the number of seconds to the time, if the number of seconds is greater than 60 then
         * the function will automatically rollover the number of minutes and hours accordingly.
         * 
         * Seconds can be positive or negative.
         */
        void addSeconds(int8_t seconds);

        /* 
         * Add the number of minutes to the time, if the number of minutes is greater than 60 then
         * the function will automatically rollover the number of hours accordingly.
         * 
         * Minutes can be positive or negative.
         */
        void addMinutes(int8_t minutes);

        /* 
         * Add the number of hours to the time, if the number of hours is greater than 24 then
         * the function will automatically rollover to 0.
         * 
         * Hours can be positive or negative.
         */
        void addHours(int8_t hours);
};

#endif