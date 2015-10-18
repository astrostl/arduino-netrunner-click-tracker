const int button1Pin = 12;
const int button2Pin = 11;

const int corpPins[] = {7,8,9};
const int runnerPins[] = {3,4,5,6};

int litCorpPins = 0, litRunnerPins = 0;

void setup()
{
  int index;
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  for(index = 0; index < 3; index++)
  {
    pinMode(corpPins[index], OUTPUT);
  }
  
  for(index = 0; index < 4; index++)
  {
    pinMode(runnerPins[index], OUTPUT);
  }
  
}


void loop()
{
  int button1State, button2State, index;

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  
  if (button1State == LOW )
  {
    if (litCorpPins < 3)
    {
      litCorpPins = litCorpPins + 1;
      for(index = litCorpPins; index != 0; index--)
      {
        digitalWrite(corpPins[index-1], HIGH);
      }
    } else {
      litCorpPins = 0;
      for(index = 0; index < 4; index ++)
      {
        digitalWrite(corpPins[index], LOW);
      }
    }
    delay(250);
  }
  
  if (button2State == LOW )
  {
    if (litRunnerPins < 4)
    {
      litRunnerPins = litRunnerPins + 1;
      for(index = litRunnerPins; index != 0; index--)
      {
        digitalWrite(runnerPins[index-1], HIGH);
      }
    } else {
      litRunnerPins = 0;
      for(index = 0; index < 4; index ++)
      {
        digitalWrite(runnerPins[index], LOW);
      }
    }
    delay(250);
  }

}

