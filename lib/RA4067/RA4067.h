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
        // Use this init for a demux
        RA4067(int s0, int s1, int s2, int s3, int readPin);
        // Set the Enable Pin
        void setEnablePin(int enable);
        // Set the multiplexer pin to "pinToSet"
        void setPin(int pinToSet);
        // Get what pin is currently set
        int getCurrentPin();
        // Enable the 4051
        void on();
        // Disable the 4051
        void off();
        // Demux digital read
        int RADigitalRead();
        // Demux analog read
        int RAAnalogRead();
    protected:
        int             m_s0;
        int             m_s1;
        int             m_s2;
        int             m_s3;
        int             m_e;
        int             m_enableBit;
        int             m_eb;
        int             m_re;
        int             m_currentPin;
        int             m_readPin;
    private:
};
#endif
