/*
 * Aditya Wahyu Pradhana
 * Timer
 * July 20, 2021
*/

#define over 60000

void setup()
{
  Serial.begin(9600);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 3035;
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK |= (1 << TOIE1);
  DDRD |= (1 << PD2);
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = 3035;

  if (millis() >= over)
  {
    Serial.println("time over");
    PORTD &= ~(1 << PD2);
    
  }
  else if (millis() < over)
  {
    Serial.println("ON!!");
    PORTD |= (1 << PD2);
  }
}

void loop()
{
  
}
