  #include "clock.h"
    //Set the clock to the specified time 
    void Clock::setClock (int h, int m, int s, string mer)
    {
       hour = h;
       minute = m;
       second = s; 
       meridian = mer;
    }

    //Display the time in standard notation
    void Clock::displayStandard()
    {
      cout << hour<<':'<<minute<<':'<<second<<' ' << meridian ;
    }

    //Display the time in military notation
    void Clock::displayMilitary()
    {
      int militaryHour = hour;
  
      //if it is pm and it isn't 12:00 noon, then add 
      //12 hours to the time
      if (meridian == "PM" && hour != 12)
          militaryHour += 12;

      //if it is 12:00 midnight, then subtract 12 hours
      if (meridian == "AM" && hour == 12)
          militaryHour -= 12;

      cout << militaryHour << ':' << minute <<  ':' << second;
    }
