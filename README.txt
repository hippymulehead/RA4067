RA4067

PlatformIO code to control a 4067 mux/demux chip in an OOP kinda way.
Simple object for controlling a 4051 multiplexer.  This just does the writes
and keeps track of the pin that's set on the 4051.

Init the object and set the pins to use for s0-s2
RA4067 myMux(int s0, int s1, int s2, int s3);

Use this init for a demux
RA4067 myDeMux(int s0, int s1, int s2, int s3, int readPin);

Set the Enable Pin
myMux.setEnablePin(int enable);

Set the multiplexer pin to "pinToSet"
myMux.setPin(int pinToSet);

Get what pin is currently set
myMux.getCurrentPin();

Enable the 4051
myMux.on();

Disable the 4051 Outputs
myMux.off();

Demux digital read
myDeMux.RADigitalRead();

Demux analog read
myDeMux.RAAnalogRead();
