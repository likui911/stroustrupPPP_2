/*
 *Implement leapyear() from §9.8.
 */

// https://en.wikipedia.org/wiki/Leap_year#Algorithm
bool leapyear(int y)
{
    if (y % 4 != 0)
        return false;
    else if (y % 100 != 0)
        return true;
    else if (y % 400 != 0)
        return false;
    return true;
}