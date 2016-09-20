#include <Servo.h>  
 Servo servo1;          //  Alt Motor Tanımlandı
 Servo servo2;          //  Üst Motor Tanımlandı
 int ldrAsagi=0;        //  Pin0 Tanımlandı, Aşağı Hareket için
 int ldrYukari=1;       //  Pin1 Tanımlandı, Yukarı Hareket için
 int ldrSol=2;          //  Pin2 Tanımlandı, Sola Hareket için
 int ldrSag=3;          //  Pin3 Tanımlandı, Sağa Hareket için 
 int servo1Poz=90;       //  Alt motor için Pozisyon değer değişkeni tanımlandı
int servo2Poz=90;        //  Üst motorun Pozisyonu
 void setup()  
 {  
  
  servo1.attach(9);    // 9 numaralı pin alt motora bağlandı
servo2.attach(10);     // 10 numaralı pin üst motora bağlandı  
  servo1.write(servo1Poz);  // Alt motorun başlangıç pozisyonu 90 yapıldı  
  servo2.write(servo2Poz);  // Üst motorun başlangıç pozisyonu 90 yapıldı.
 }  
 
 void loop()  
 {  
  int ldrAsagiDeger=analogRead(ldrAsagi);   //Aşağı yönlü ldr değeri okunarak değişkene atandı
  int ldrYukariDeger=analogRead(ldrYukari); //Yukarı yönlü ldr değeri okunarak değişkene atandı  
  int ldrSolDeger=analogRead(ldrSol);       //Sol yönlü ldr değeri okunarak değişkene atandı  
  int ldrSagDeger=analogRead(ldrSag);       //Sağ yönlü ldr değeri okunarak değişkene atandı 
 
int fark1=ldrAsagiDeger-ldrYukariDeger;   
int fark2=ldrSolDeger-ldrSagDeger;


 
  if(ldrAsagiDeger<950 || ldrYukariDeger<950)    //Işık varsa 
  {  
    if(fark1>=10)                //Işık Aşağıdan geliyorsa 
    {  
     servo1Poz=servo1Poz+2;  
     servo1.write(servo1Poz);     // üstteki motoru aşağı hareketlendirir  
     delay(50);     
     
    }  
    else if(fark1<=-10)              // ışık Yukarıdan geliyorsa
    {  
     servo1Poz=servo1Poz-2;  
     servo1.write(servo1Poz);     // üstteki motor yukarı hareket eder
     delay(50);                // dönüş hızı 
    } 

     
 
  } 
if(ldrSolDeger<950 || ldrSagDeger<950)    //ışık varsa ışık düştükçe değer yükselir
  {  
    if(fark2>=10)                //Işık soldan geliyorsa 
    {  
     servo2Poz=servo2Poz+2;  
     servo2.write(servo2Poz);     // Servoyu döndür 
     delay(50);      // Konuma ulaşmak için 30 ms bekler 
      
    }  
    else if(fark2<=-10)              //Işık sağdan geliyorsa
    {  
     servo2Poz=servo2Poz-2;  
     servo2.write(servo2Poz);     
     delay(50);  
     
    }
  
 
  }
/*if(fark1>10 && fark2>10 )
  {
   servo2Poz=90;
   servo2.write(servo2Poz);
   delay(30);
   
    servo1Poz=servo1Poz-2;
   servo1.write(servo1Poz);
   delay(30);
   
 
}
*/


 

  
   
   

 }                            
