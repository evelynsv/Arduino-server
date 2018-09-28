#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0,90, 0xA2, 0xDA, 0x0D, 0x83, 0x15};

IPAddress ip(10, 20, 32, 15);
IPAddress gateway(10, 20, 32, 254);
IPAddress subnet(255, 255, 255, 0);

EthernetServer server(80);

void setup(){
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  Serial.begin(9600);
  Serial.print("Servidor rodando em: ");
  Serial.print(Ethernet.localIP());
  }

  void loop(){
    EthernetClient client = server.available();

    if(client){
      while(client.connected()){
        if(client.available()){
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html>");
            client.println("<head><title>Ola mundo</title></head>");
            client.println("<body>");
              client.println("O conteúdo vai aqui!");
            client.println("</body>");
          client.println("</html>");
      

          client.stop();
          }
        }
      }
    }
