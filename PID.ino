// Exponential Smoothing Filter Class
class ExponentialSmoothingFilter {
private:
  double alpha;
  double filteredValue;
   
public:
  ExponentialSmoothingFilter(double input_alpha) {
    alpha=input_alpha ; 
    filteredValue=0;}

  double apply_filter(double input) {
    filteredValue = alpha * input + (1 - alpha) * filteredValue;
    return filteredValue;
  }
};

// PID Controller Class
class PIDController {
private:
  double Kp, Ki, Kd;
  double setpoint, output, error, previousError, integral, derivative;
  unsigned long previousTime;
  const double integralMax = 1000.0; // Adjust integral maximum

public:
  PIDController(double input_Kp, double input_Ki, double input_Kd) {
    Kp = input_Kp;
    Ki = input_Ki;
    Kd = input_Kd;
    previousTime = millis(); 
    integral = 0; 
    previousError = 0;
  }

  void setSetpoint(double input_setpoint) { 
    setpoint = input_setpoint; 
    }

  void calculate(double input) {
    long currentTime = millis();
    double dt = (currentTime - previousTime) / 1000.0; // Convert milliseconds to seconds

    error = setpoint - input;

    integral += error * dt;
    integral = constrain(integral, -integralMax, integralMax);

    derivative = (error - previousError) / dt;

    output = Kp * error + Ki * integral + Kd * derivative;
    output = constrain(output, 0, 255); // Adjust output range as needed

    previousError = error;
    previousTime = currentTime;
  }

  double getOutput() { return output; }

};

// Create PID controller and filter objects
PIDController pidController(1.0, 0.1, 0.01); // Adjust PID parameters as needed
ExponentialSmoothingFilter Filter(0.1); // Adjust alpha value for filtering

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT); //motorpin =11
  
  // Set initial setpoint
  pidController.setSetpoint(128); // Adjust setpoint as needed with the desired speed
}

void loop() {
  
  // Read raw input from encoder 
  double raw_input = analogRead(A0);
  
  // Convert encoder value to speed range
  double motor_speed = map(raw_input, 0, 1023, 0, 255);

  // Apply the Exponential Smoothing Filter to smooth the input
  double filteredInput = Filter.apply_filter(motor_speed);

  // Ensure filteredInput is within the desired speed range
  filteredInput = constrain(filteredInput, 0, 255);

  // Compute PID output based on filtered input
  pidController.calculate(filteredInput);

  // Write PID output to motor
  analogWrite(11, pidController.getOutput());

  // Serial Monitoring
  Serial.print("Raw Input: ");
  Serial.print(raw_input);
  Serial.print(" | Filtered Input: ");
  Serial.print(filteredInput);
  Serial.print(" | PID Output: ");
  Serial.println(pidController.getOutput());

  delay(100);
}
