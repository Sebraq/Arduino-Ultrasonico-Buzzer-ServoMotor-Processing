import processing.serial.*;
Serial puerto;
float datos;
int n=2;
float[] data = new float[n];
PGraphics pg1;
void setup()
{

  puerto=new Serial(this, "COM5", 9600);
  size(700, 700);
  puerto.bufferUntil('\n');
  pg1=createGraphics(190, 35);
}

void draw()
{
  PG_DRAW();
  image(pg1, 0, 0);
  if (data[1]==0) {
    background(0);
  }
  stroke(0, 255, 0, 10);
  strokeWeight(20);

  //***dibuja lineas en nuevo marco de referencia
  pushMatrix();
  translate(width/2, 10);
  rotate(HALF_PI-data[1]*PI/180);
  line(0, 0, 0, 800);
  stroke(255, 0, 0, 50);
  line(0, data[0]*3, 0, 800);
  popMatrix();
  //******
}

void serialEvent(Serial puerto) {
  String bufString = puerto.readString();
  data = float(split(bufString, ','));
}
void PG_DRAW() {
  pg1.beginDraw();
  pg1.background(0);
  if (data[1]!=0) {
    pg1.text("Valor de la distancia: " + data[0], 35, 25);
    datos=data[0];
  } else {
    pg1.text("Valor de la distancia: " + datos, 35, 25);
  }
  pg1.endDraw();
}
