int unit = 300;
int dotLength = unit;
int dashLength = unit * 3;
int partSpaceLength = unit;
int letterSpaceLength = unit * 3;
int wordSpaceLength = unit * 7;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  sos();
}

void sos() {
  s();o();s();
  wordDelay();
}

void helloWorld() {
  hello();world();
}

void hello() {
  h();e();l();l();o();
  wordDelay();
}

void world() {
  w();o();r();l();d();
  wordDelay();
}

void a() {
  dot();dash();
  letterDelay();
}

void b() {
  dash();dot();dot();dot();
  letterDelay();
}

void c() {
  dash();dot();dash();dot();
  letterDelay();
}

void d() {
  dash();dot();dot();
  letterDelay();
}

void e() {
  dot();
  letterDelay();
}

void f() {
  dot();dot();dash();dot();
  letterDelay();
}

void g() {
  dash();dash();dot();
  letterDelay();
}

void h() {
  dot();dot();dot();dot();
  letterDelay();
}

void i() {
  dot();dot();
  letterDelay();
}

void j() {
  dot();dash();dash();dash();
  letterDelay();
}

void k() {
  dash();dot();dash();
  letterDelay();
}

void l() {
  dot();dash();dot();dot();
  letterDelay();
}

void m() {
  dash();dash();
  letterDelay();
}

void n() {
  dash();dot();
  letterDelay();
}

void o() {
  dash();dash();dash();
  letterDelay(); 
}

void p() {
  dot();dash();dash();dot();
  letterDelay();
}

void q() {
  dash();dash();dot();dash();
  letterDelay();
}

void r() {
  dot();dash();dot();
  letterDelay();
}

void s() {
  dot();dot();dot();
  letterDelay();
}

void t() {
  dash();
  letterDelay();
}

void u() {
  dot();dot();dash();
  letterDelay();
}

void v() {
  dot();dot();dot();dash();
  letterDelay();
}

void w() {
  dot();dash();dash();
  letterDelay();
}

void x() {
  dash();dot();dot();dash();
  letterDelay();
}

void y() {
  dash();dot();dash();dash();
  letterDelay();
}

void z() {
  dash();dash();dot();dot();
  letterDelay();
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotLength);
  digitalWrite(LED_BUILTIN, LOW);
  partDelay();
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashLength);
  digitalWrite(LED_BUILTIN, LOW);
  partDelay();
}

void partDelay() {
  delay(partSpaceLength);
}

void letterDelay() {
  delay(letterSpaceLength);
}

void wordDelay() {
  delay(wordSpaceLength);
}
