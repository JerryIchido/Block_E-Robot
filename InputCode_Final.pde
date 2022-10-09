import processing.serial.*;  //imports library used for wireless comm with the HC-05
Serial myPort;               // declares Serial Port object from library
String Text = "";

void setup()
{
 size(900,1000);                         // create window of this size
 myPort=new Serial(this, "COM9", 115200);  //COM port will likely be different, try different ones until it works (usually one of COM3-COM7)
 myPort.bufferUntil('\n');               //delays calling serialEvent unitl reaching '\n'
}

void serialEvent(Serial myPort){        //serialEvent is called whenever data is available
  Text = myPort.readStringUntil('\n');   //reads Serial.println() from Arduino
}

int state = 0;
int x = 0;
void draw()
{

  background(237,240,241);        // sets background to a color, parameters correspond to an RGB code
  fill(20,160,133);               // sets color we will use to fill shapes
  stroke(33);                     // sets color used for border around shapes
  strokeWeight(1);                // sets width of stroke when drawing shapes
  
  rect(x,700,50,50,10);           //creates a rectangle at x,y with size width,height
  x+=1;
  if (x == 800)
    x=0;
  
  fill(0);
  textSize(32);
  text(Text, 400, 700);           //draws text at x,y
    
 
  if(state == 1){
    myPort.write('p');
  }
  if(state == 2){
    myPort.write(key);
  }
}

void keyReleased(){
  state = 1;
}

void keyPressed(){
  state = 2;
}
