/*
UYSX697VKRSU
ist_VUaJyskNUvgX-LpFlZbuuzTQ-AiQeoi1
https://groker.init.st/api/events?accessKey=ist_VUaJyskNUvgX-LpFlZbuuzTQ-AiQeoi1&bucketKey=UYSX697VKRSU
        
        /*

everything that goes to intial state NEEDS to be in json format
{"key":"temperature", "value":79}

[ {}, {} ]

*/

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int temperature = random(74, 83);
  // Trigger the integration

  Particle.publish("initial_state_single", String(temperature), PRIVATE);

  String json = "{\"value1\":90, \"value2\":100}";
  Particle.publish("initial_state_single", json, PRIVATE);
  // Wait 60 seconds
  delay(5000);

}