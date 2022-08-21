#define button1_pin 2
#define button2_pin 3

unsigned long debounceDelay = 5;

int count = 100;
class Swtich
{
public:

    int buttonState = false;
    int lastButtonState = false;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 5;
    int define_pin;
    Swtich(int pin, int debounceTime)
    {
        define_pin = pin;
        pinMode(pin, INPUT);
        debounceDelay = debounceTime;
    }
    void runtime()
    {
        int reading = digitalRead(define_pin);
        if (reading != lastButtonState)
        {
            // reset the debouncing timer
            lastDebounceTime = millis();
        }
        if ((millis() - lastDebounceTime) > debounceDelay)
        {
            if (reading != buttonState)
            {
                buttonState = reading;
            }
        }
        lastButtonState = reading;
    }
    int get()
    {
        return buttonState;
    }
};
Swtich switch1(button1_pin,debounceDelay);
Swtich switch2(button2_pin,debounceDelay);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if(switch1.get() == 1 && switch2.get() == 1){
        Serial.println("both button have press so plus and minus is nothing");
    }
    else if(switch1.get() == 1){
        count++;
        while(switch1.get()==1){switch1.runtime();}
    }
    else if(switch2.get() == 1){
        count--;
        while(switch2.get()==1){switch2.runtime();}
    }
    Serial.println("count:"+String(count));
    switch1.runtime();
    switch2.runtime();
    // Serial.println("SW1:"+String(digitalRead(button1_pin))+" SW2:"+String(digitalRead(button2_pin)));
}