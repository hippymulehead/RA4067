#define RA4067_h
#ifdef RA4067_h

/*
Simple object for controlling a 4051 multiplexer.  This just does the writes
and keeps track of the pin that's set on the 4051.
*/

class RA4067 {
    public:
        // Init the object and set the pins to use for s0-s2
        RA4067(int s0, int s1, int s2, int s3);
        // Use this init if you're connecting the enable pin (6)
        RA4067(int s0, int s1, int s2, int s3, int enable);
        // Set the multiplexer pin to "pinToSet"
        void setPin(int pinToSet);
        // Get what pin is currently set
        int getCurrentPin();
        // Enable the 4051
        void on();
        // Disable the 4051
        void off();
    protected:
        int             _s0;
        int             _s1;
        int             _s2;
        int             _s3;
        int             _e;
        int             _enableBit;
        int             _eb;
        int             _currentPin;
    private:
};
#endif