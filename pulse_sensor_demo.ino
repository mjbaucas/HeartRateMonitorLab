int const PULSE_SENSOR_PIN = 0;   // Pulse signal pin connected to A0

int pulse_signal;          // Holds pulse sensor signal
int threshold = 510;       // Determines if pulse signal value counts as a heart beat

void setup() {
	pinMode(LED_BUILTIN,OUTPUT);  // Use built-in LED to blink to pulse
	Serial.begin(9600);          
}

void loop() {

	pulse_signal = analogRead(PULSE_SENSOR_PIN); // Read pulse sensor value from pin

	Serial.println(pulse_signal); // Send pulse signal value to Serial Plotter       

  // Blink LED if signal crosses threshold
	if(pulse_signal > threshold){                
		digitalWrite(LED_BUILTIN,HIGH);
	} else {
		digitalWrite(LED_BUILTIN,LOW);     
	}
	delay(10); // Delay to control signal frequency
}

