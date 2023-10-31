//two questions: should magic number be random number, does range include zero and 100

void setup() {
  // put your setup code here, to run once:

  //Ardiuino muct receive a Serial input at a Baud rate of 57600
  Serial.begin(57600);
}

bool playing = true;
int target = 42;

//tests how close the input is to the magic number
//returns nothing
//arguments: user guess and magic number
void checkInput(int input, int target){
  //Serial.println(input);
  //Serial.println(target);
  if (input < target){
    Serial.print(input);
    Serial.println(" is too low");
  }else if(input > target){
    Serial.print(input);
    Serial.println(" is too high");
  }else{
    Serial.print(input);
    Serial.println(" is Correct!");
    playing = false;
  }
}

//tests that the range of the input number is correct
//promt says between 0 and 100 (including 0 and 100?)
//arguments: user guess
//returns boolean of whether it is in the range or not
bool checkRange(int input){
  if (input < 0){
    Serial.print(input);
    Serial.println(" invalid number must be > 0");
    return false;
  }else if(input > 100){
    Serial.print(input);
    Serial.println(" invalid number must be < 100");
    return false;
  }else{
    return true;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(playing == true){
    Serial.println("ENTER NUMBER b/t 0 and 100:");

    String userInput;
    int integerInput;
    while(Serial.available() == 0){
    }
    userInput = Serial.readStringUntil("\n");
    userInput.trim();
    integerInput = userInput.toInt();
    
    if((userInput.compareTo("0") != 0) && (integerInput == 0)){
      Serial.print(userInput);
      Serial.println(" is not a number. Please enter a number");
    }else{
      bool inRange = checkRange(integerInput);
      if(inRange == true){
        checkInput(integerInput, target);
      }
    }
  }
}
