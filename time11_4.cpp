/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/25/2014 05:12:52 PM
 *
 *    Description:  book page 624 problem 4
 *
 * ===========================================================================
 */

#ifndef MYTIME_H_
#define MYTIME_H_

class Time {
  private:
    int hours;
    int minutes;
  public:
    Time();
    Time(int h, int m = 0);
    void addMin(int m);
    void addHr(int h);
    //Time operator+(const Time & t) const;
    friend Time operator+(const Time & t0, const Time & t1); 
    void show() const;
};
#endif

#include <iostream>

using namespace std;

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::addMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes = minutes % 60;
}

void Time::addHr(int h) {
  hours += h;
}

//Time Time::operator+(const Time & t) const {
  //Time sum;
  //sum.minutes = (minutes + t.minutes) % 60;
  //sum.hours = hours + t.minutes/60 + t.hours;
//}

Time operator+(const Time & t0, const Time & t1) {
  Time sum;
  sum.minutes = (t0.minutes + t1.minutes) % 60;
  sum.hours = t0.hours + (t0.minutes + t1.minutes)/60 + t1.hours;

  return sum;
}

void Time::show() const {
  cout << "Hours " << hours << "  Minutes " << minutes << endl;
}

int main () {
  Time aida(3, 35);
  Time tosca(2, 48);
  //aida.show();
  //tosca.show();
  Time sum;

  sum = operator+(aida, tosca);
  //sum = aida + tosca;
  sum.show();

}
