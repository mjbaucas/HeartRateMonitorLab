// Constants
const int PULSE_SENSOR_PIN = 0;  // Pulse signal pin connected to A0
int pulse_signal;                 // Holds pulse sensor signal for debugging
const int threshold = 514;       // Determines if pulse signal value counts as a heart beat

// Variables for elapsed time
unsigned long start_time;
unsigned long end_time;
unsigned long total_time = 0;

// Variables for heart rate
int flag = 0;
int heart_beat_count = 0;
float heart_rate = 0;

void setup() 
{
	Serial.begin(9600);   
}
 
void loop() 
{
  start_time = millis();
  for(int i = 0; i < 250; i++){
    // Get pulse signal
    pulse_signal = analogRead(PULSE_SENSOR_PIN); // Read pulse sensor value from pin

    // Debugging pulse signal
    //Serial.println(pulse_signal); // Send pulse signal value to Serial Plotter      
    
    // Heartbeat logic
    // Count as heartbeat if pulse signal is above threshold and if crossing flag is off
    if(pulse_signal > threshold && flag == 0){
      heart_beat_count = heart_beat_count + 1;
      flag = 1;                
	  } else if (pulse_signal > threshold && flag == 1){
      // Do not count as heartbeat if value is above threshold but pulse signal value has not gone back to zero yet 
	  }

    // If pulse signal value went back under the threshold, set turn the crossing flag off
    if (pulse_signal < 512 && flag == 1)
    {
      flag = 0;
    }

    // If at any point heart rate count becomes negative, set it back to zero
    if (heart_beat_count < 0)
    {
      heart_beat_count = 0;
    }

    // Add a small delay to reduce CPU usage
    delay(20);
  }
  end_time = millis();
  total_time = total_time + (end_time - start_time); // Get total elapsed time from start of measurement
  
  // Calculate heart rate
  heart_rate = (heart_beat_count * 60.0 * 1000.0) / total_time; // Don't forget to account for units

  Serial.print("heartrate: ");
  Serial.println(heart_rate);
  delay(100);
}


