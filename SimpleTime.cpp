#include "SimpleTime.h"
#include <Arduino.h>

SimpleTime::SimpleTime(void)
{
    this->_hours = 0;
    this->_minutes = 0;
    this->_seconds = 0;
}

SimpleTime::SimpleTime(int hours, int minutes, int seconds) : _hours(hours), _minutes(minutes), _seconds(seconds)
{
    this->_rollover();
}

void SimpleTime::set(int hours, int minutes, int seconds)
{
    this->_hours = hours;
    this->_minutes = minutes;
    this->_seconds = seconds;
    this->_rollover();
}

void SimpleTime::_rollover(void)
{
    if(this->_seconds > 59)
    {
        this->_seconds -= 60;
        this->_minutes ++;
    }

    if(this->_seconds < 0)
    {
        this->_seconds += 60;
        this->_minutes --;
    }

    if(this->_minutes > 59)
    {
        this->_minutes -= 60;
        this->_hours ++;
    }

    if(this->_minutes < 0)
    {
        this->_minutes += 60;
        this->_hours --;
    }

    if(this->_hours > 23)
    {
        this->_hours -= 24;
    }

    if(this->_hours < 0)
    {
        this->_hours += 24;
    }
}

int SimpleTime::getHours()
{
    return this->_hours;
}

int SimpleTime::getMinutes()
{
    return this->_minutes;
}

int SimpleTime::getSeconds()
{
    return this->_seconds;
}

void SimpleTime::tick(void)
{
    return this->addSeconds(1);
}

void SimpleTime::addSeconds(int8_t seconds)
{
    this->_seconds += seconds;
    this->_rollover();
}

void SimpleTime::addMinutes(int8_t minutes)
{
    this->_minutes += minutes;
    this->_rollover();
}

void SimpleTime::addHours(int8_t hours)
{
    this->_hours += hours;
    this->_rollover();
}