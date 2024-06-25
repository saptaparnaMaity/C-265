#include <RTClib.h>

RTC_DS1307 rtc;

String rtc_date = "";
String rtc_time = "";

void setup(){

  Serial.begin(9600);
  
  if (!rtc.begin()){
    Serial.println("RTC not initialised");
    while(true);
  }
  Serial.println("RTC found");
}




void loop(){

  //  RTC date and time
  DateTime dt = rtc.now();
  rtc_date = get_date(dt);
  Serial.println(rtc_date);
  rtc_time = get_time(dt);
  Serial.println(rtc_time);

  //  for better working of simulator
  delay(1000);
}

String get_time(DateTime current){

  int hour = current.hour();
  int minute = current.minute();
  int second = current.second();

  String current_time = "Time : " + String(hour) + ":" + String(minute) + 
                        ":" + String(second);

  return current_time;
}

String get_date(DateTime current){

  int year = current.year();
  int month = current.month();
  int day = current.day();

  String current_date = "Date : " + String(day) + "/" + String(month) + 
                "/" + String(year);
  
  return current_date;
}